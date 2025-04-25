use rand::prelude::IndexedRandom;
use rand::Rng;
use std::io::{ self, Write };
use std::process::Command;
use std::fs::{ self, File };
use std::path::Path;

#[derive(Clone, PartialEq)]
enum Barva {
    Cervena,
    Zelena,
    Modra,
    Zluta,
    Bila,
    Fialova,
    Oranzova,
    Tyrkysova,
}

impl Barva {
    fn na_retezec(&self) -> &str {
        match self {
            Barva::Cervena => "R",
            Barva::Zelena => "G",
            Barva::Modra => "B",
            Barva::Zluta => "Y",
            Barva::Bila => "W",
            Barva::Fialova => "P",
            Barva::Oranzova => "O",
            Barva::Tyrkysova => "T",
        }
    }

    fn z_retezce(s: &str) -> Option<Barva> {
        match s.to_uppercase().as_str() {
            "R" => Some(Barva::Cervena),
            "G" => Some(Barva::Zelena),
            "B" => Some(Barva::Modra),
            "Y" => Some(Barva::Zluta),
            "W" => Some(Barva::Bila),
            "P" => Some(Barva::Fialova),
            "O" => Some(Barva::Oranzova),
            "T" => Some(Barva::Tyrkysova),
            _ => None,
        }
    }

    fn vsechny_barvy() -> Vec<Barva> {
        vec![
            Barva::Cervena,
            Barva::Zelena,
            Barva::Modra,
            Barva::Zluta,
            Barva::Bila,
            Barva::Fialova,
            Barva::Oranzova,
            Barva::Tyrkysova
        ]
    }
}

#[derive(Clone)]
struct Vysledek {
    presne: usize,
    castecne: usize,
    pozicni_hodnoceni: Vec<Option<bool>>,
    je_presna_pozice: bool,

    // true = cerna (spravna barva a pozice)
    // false = bila (spravna barva)
    // None = nic
}

struct Hra {
    pocet_kamenu: usize,
    max_pokusu: usize,
    tajny_kod: Vec<Barva>,
    odhady: Vec<Vec<Barva>>,
    vysledky: Vec<Vysledek>,
}

struct Nastaveni {
    pocet_barev: usize,
    opakovani_barev: bool,
    pocet_policek: usize,
    presna_pozice: bool,
}

struct Statistiky {
    vyhry: usize,
    prohry: usize,
}

impl Statistiky {
    fn nacti_ze_souboru() -> Self {
        let cesta_souboru = "statistiky.txt";

        if Path::new(cesta_souboru).exists() {
            match fs::read_to_string(cesta_souboru) {
                Ok(obsah) => {
                    let radky: Vec<&str> = obsah.lines().collect();
                    if radky.len() >= 2 {
                        // pokud se prvni dva radky daji uspesne prevest na cisla
                        // vytvori a vrati se struktura Statistiky
                        if let (Ok(vyhry), Ok(prohry)) = (radky[0].parse(), radky[1].parse()) {
                            return Statistiky { vyhry, prohry };
                        }
                    }
                }
                Err(_) => println!("chyba pri cteni souboru se statistikami"),
            }
        }

        // vrati vychozi statistiky, pokud soubor neexistuje nebo je neplatny
        Statistiky { vyhry: 0, prohry: 0 }
    }

    fn uloz_do_souboru(&self) {
        let cesta_souboru = "statistiky.txt";
        match File::create(cesta_souboru) {
            Ok(mut soubor) => {
                let obsah = format!("{}\n{}", self.vyhry, self.prohry);
                if let Err(_) = soubor.write_all(obsah.as_bytes()) {
                    println!("chyba pri zapisu statistik do souboru");
                } else {
                    println!("statistiky byly ulozeny do souboru {}", cesta_souboru);
                }
            }
            Err(_) => println!("nelze vytvorit soubor pro ulozeni statistik"),
        }
    }
}

impl Hra {
    fn nova_s_nastavenim(nastaveni: &Nastaveni) -> Hra {
        let mut hra = Hra {
            pocet_kamenu: nastaveni.pocet_policek,
            max_pokusu: 10,
            tajny_kod: Vec::new(),
            odhady: Vec::new(),
            vysledky: Vec::new(),
        };

        hra.generuj_kod_s_nastavenim(nastaveni);
        hra
    }

    fn generuj_kod_s_nastavenim(&mut self, nastaveni: &Nastaveni) {
        let mut rng = rand::rng();
        let barvy = Barva::vsechny_barvy()
            .into_iter()
            .take(nastaveni.pocet_barev)
            .collect::<Vec<_>>();

        if nastaveni.opakovani_barev {
            // pokud je povoleno opakovani, vybereme nahodne z dostupnych barev
            self.tajny_kod = (0..self.pocet_kamenu)
                .map(|_| barvy.choose(&mut rng).unwrap().clone())
                .collect();
        } else {
            // ✨
            // k tomuhle by se nemelo jit dostat, protoze
            // pocet_barev je vzdy <= pocet kamenu
            // ✨
            //
            // pokud neni povoleno opakovani, zajistime, ze kazda barva je vybrána jen jednou
            let mut dostupne_barvy = barvy.clone();
            let mut kod = Vec::with_capacity(self.pocet_kamenu);

            // overime, ze mame dost barev
            if nastaveni.pocet_barev < self.pocet_kamenu {
                println!(
                    "neni dost barev ({}) pro vytvoreni tajnyho kodu bez opakovani pro {} pozic",
                    nastaveni.pocet_barev,
                    self.pocet_kamenu
                );
                println!("nektery barvy se mohou opakovat");
            }

            for _ in 0..self.pocet_kamenu {
                if dostupne_barvy.is_empty() {
                    // pokud dojdou barvy, zacneme znova s plnym seznamem
                    dostupne_barvy = barvy.clone();
                }

                let index = rng.random_range(0..dostupne_barvy.len());
                kod.push(dostupne_barvy.remove(index));
            }

            self.tajny_kod = kod;
        }
    }

    fn vyhodnot_odhad(&mut self, odhad: Vec<Barva>, presna_pozice: bool) -> Vysledek {
        let mut presne = 0;
        let mut pozicni_hodnoceni = vec![None; self.pocet_kamenu];

        let mut pouzite_kod = vec![false; self.pocet_kamenu];
        let mut pouzite_odhad = vec![false; self.pocet_kamenu];

        // nejdriv zjistime presny shody (cerne kameny) pro oba rezimy
        for i in 0..self.pocet_kamenu {
            if i < odhad.len() && odhad[i] == self.tajny_kod[i] {
                presne += 1;
                pouzite_kod[i] = true;
                pouzite_odhad[i] = true;
                pozicni_hodnoceni[i] = Some(true); // cerna - spravna barva i pozice
            }
        }

        let mut castecne = 0;
        // hledame castecny shody pro hodnoceni s presnou pozici

        // presna_pozice == true:
        //      projde odhad a zjisti,
        //      jestli jsou barvy z odhadu v tajnym kodu
        //      pricemz taky ulozi neshody pozic
        // presna_pozice == false:
        //      projde odhad a tajny kod,
        //      aby spocital pocet castecnych shod
        //      (spravna barva, spatna pozice) s tim, ze pouzije
        //      pomocny pole `pouzite_kod` a `pouzite_odhad`,
        //      aby zabranil zapocitani stejny barvy vickrat
        if presna_pozice {
            // hodnoceni s presnou pozici - kazdy kamen na svem miste
            for i in 0..self.pocet_kamenu {
                if i >= odhad.len() || pouzite_odhad[i] {
                    continue;
                }

                // hledame, jestli barva existuje v tajnem kodu
                let mut nalezeno = false;
                for j in 0..self.pocet_kamenu {
                    if !pouzite_kod[j] && odhad[i] == self.tajny_kod[j] {
                        pouzite_kod[j] = true;
                        nalezeno = true;
                        break;
                    }
                }

                if nalezeno {
                    pozicni_hodnoceni[i] = Some(false); // bila - spravna barva, spatna pozice
                }
            }
        } else {
            // hodnoceni bez presny pozice - kameny jsou zleva doprava
            for i in 0..self.pocet_kamenu {
                if i >= odhad.len() || pouzite_odhad[i] {
                    continue;
                }

                for j in 0..self.pocet_kamenu {
                    if !pouzite_kod[j] && odhad[i] == self.tajny_kod[j] {
                        castecne += 1;
                        pouzite_kod[j] = true;
                        pouzite_odhad[i] = true;
                        break;
                    }
                }
            }
        }

        let vysledek = Vysledek {
            presne,
            castecne,
            pozicni_hodnoceni: pozicni_hodnoceni.clone(),
            je_presna_pozice: presna_pozice,
        };

        self.odhady.push(odhad.clone());
        self.vysledky.push(vysledek.clone());

        // zobrazime hodnoceni podle vybranyho zpusobu
        if presna_pozice {
            println!("hodnoceni (presna pozice):");
            for i in 0..self.pocet_kamenu {
                match pozicni_hodnoceni[i] {
                    Some(true) => print!("cerna "),
                    Some(false) => print!("bila "),
                    None => print!("nic "),
                }
            }
            println!();
        } else {
            println!("hodnoceni (bez presne pozice):");
            for _ in 0..vysledek.presne {
                print!("cerna ");
            }
            for _ in 0..vysledek.castecne {
                print!("bila ");
            }
            println!();
        }

        vysledek
    }

    fn je_vyherce(&self) -> bool {
        if let Some(posledni) = self.vysledky.last() {
            posledni.presne == self.pocet_kamenu
        } else {
            false
        }
    }

    fn je_konec(&self) -> bool {
        self.je_vyherce() || self.odhady.len() >= self.max_pokusu
    }

    fn zobraz_stav(&self) {
        println!("=== LOGIK ===");
        println!("hadej kombinaci {} barev", self.pocet_kamenu);

        for i in 0..self.max_pokusu {
            print!("{:2}. ", i + 1);

            if i < self.odhady.len() {
                for barva in &self.odhady[i] {
                    print!("{} ", barva.na_retezec());
                }

                print!("| ");

                let vysledek = &self.vysledky[i];
                if vysledek.je_presna_pozice {
                    // pozicni hodnoceni
                    for hodnoceni in &vysledek.pozicni_hodnoceni {
                        match hodnoceni {
                            Some(true) => print!("○ "), // cerna
                            Some(false) => print!("● "), // bila
                            None => print!("_ "), // nic
                        }
                    }
                } else {
                    // nepozicni hodnoceni (zleva doprava)
                    for _ in 0..vysledek.presne {
                        print!("○ ");
                    }
                    for _ in 0..vysledek.castecne {
                        print!("● ");
                    }
                    for _ in 0..self.pocet_kamenu - vysledek.presne - vysledek.castecne {
                        print!("_ ");
                    }
                }
            } else {
                for _ in 0..self.pocet_kamenu {
                    print!("_ ");
                }
                print!("|");
            }
            println!();
        }
    }

    fn zobraz_reseni(&self) {
        print!("tajnej kod byl: ");
        for barva in &self.tajny_kod {
            print!("{} ", barva.na_retezec());
        }
        println!();
    }
}

fn vyber_nastaveni() -> Nastaveni {
    println!("=== VYBER OBTIZNOSTI ===");

    let pocet_barev = vyber_moznost("vyber pocet barev (5, 6, 7, 8): ", &[5, 6, 7, 8]);
    let opakovani_barev = vyber_ano_ne("povolit opakovani barev (ano/ne): ");
    let pocet_policek = vyber_moznost("vyber pocet policek (4, 5): ", &[4, 5]);
    let presna_pozice = vyber_ano_ne("hodnoceni presna pozice (ano/ne): ");

    Nastaveni {
        pocet_barev,
        opakovani_barev,
        pocet_policek,
        presna_pozice,
    }
}

fn vyber_moznost(prompt: &str, moznosti: &[usize]) -> usize {
    loop {
        print!("{}", prompt);
        io::stdout().flush().unwrap();

        let mut vstup = String::new();
        io::stdin().read_line(&mut vstup).expect("chyba pri cteni vstupu");

        if let Ok(vyber) = vstup.trim().parse::<usize>() {
            if moznosti.contains(&vyber) {
                return vyber;
            }
        }

        println!("neplatnej input, napis '4' nebo '5'.");
    }
}

fn vyber_ano_ne(prompt: &str) -> bool {
    loop {
        print!("{}", prompt);
        io::stdout().flush().unwrap();

        let mut vstup = String::new();
        io::stdin().read_line(&mut vstup).expect("chyba pri cteni vstupu");

        match vstup.trim().to_lowercase().as_str() {
            "ano" => {
                return true;
            }
            "ne" => {
                return false;
            }
            _ => println!("neplatnej input, napis 'ano' nebo 'ne'."),
        }
    }
}

fn nacti_odhad(pocet_kamenu: usize, pocet_barev: usize) -> Vec<Barva> {
    // vytvori retezec barev oddelenej carkama.
    let barvy = Barva::vsechny_barvy()
        .iter()
        .take(pocet_barev)
        .map(|b| b.na_retezec())
        .collect::<Vec<&str>>()
        .join(",");

    loop {
        print!("napis kombinaci {} barev ({}) nebo napiste 'odhalit': ", pocet_kamenu, barvy);
        io::stdout().flush().unwrap();

        let mut vstup = String::new();
        io::stdin().read_line(&mut vstup).expect("chyba pri cteni vstupu");

        let vstup_trim = vstup.trim().to_lowercase();

        // pokud uzivatel zada "odhalit", vrati prazdny vektor jako signal
        if vstup_trim == "odhalit" {
            return vec![];
        }

        let odhad: Vec<Option<Barva>> = vstup_trim
            .chars()
            .filter(|c| !c.is_whitespace())
            .map(|c| Barva::z_retezce(&c.to_string()))
            .collect();

        // kontroluje, jestli pocet zadanejch barev odpovida expected poctu kamenu
        if odhad.len() == pocet_kamenu && odhad.iter().all(|b| b.is_some()) {
            // kontrola, ze byly pouzity jen platny barvy z vybranyho poctu
            let vse_platne = odhad.iter().all(|b| {
                if let Some(barva) = b {
                    let index = Barva::vsechny_barvy()
                        .iter()
                        .position(|x| x == barva)
                        .unwrap();
                    index < pocet_barev
                } else {
                    false
                }
            });

            if vse_platne {
                return odhad
                    .into_iter()
                    .map(|b| b.unwrap())
                    .collect();
            }
        }

        println!(
            "neplatnej input — napis {} platnejch barve ({}) nebo 'odhalit'",
            pocet_kamenu,
            barvy
        );
    }
}

// vycisti obrazovku
// podle OS
// na windows pouzije "cls", na ostatnich OS "clear"
// pokud ani jedno nefunguje, nic se nestane

#[cfg(windows)]
fn vycisti_obrazovku() {
    let _ = Command::new("cmd").args(["/c", "cls"]).status();
}

#[cfg(not(windows))]
fn vycisti_obrazovku() {
    if
        Command::new("clear")
            .status()
            .map(|s| s.success())
            .unwrap_or(false)
    {
        return;
    }
    let _ = Command::new("cmd").args(["/c", "cls"]).status();
}

// samozrejme tohle neni nejlepsi reseni, ale funguje to a je to jednodussi
fn main() {
    let nastaveni = vyber_nastaveni();
    let mut hra = Hra::nova_s_nastavenim(&nastaveni);

    // nacist statistiky ze souboru
    let mut statistiky = Statistiky::nacti_ze_souboru();

    vycisti_obrazovku();

    while !hra.je_konec() {
        hra.zobraz_stav();

        let odhad = nacti_odhad(hra.pocet_kamenu, nastaveni.pocet_barev);

        if odhad.is_empty() {
            hra.zobraz_reseni();
            break;
        }

        vycisti_obrazovku();
        hra.vyhodnot_odhad(odhad, nastaveni.presna_pozice);
    }

    hra.zobraz_stav();

    if hra.je_vyherce() {
        println!("uhadl jsi tajnou kombinaci");
        statistiky.vyhry += 1;
    } else {
        println!("neuhodl jsi tajnou kombinaci");
        print!("tajnej kod byl: ");
        for barva in &hra.tajny_kod {
            print!("{} ", barva.na_retezec());
        }
        println!();
        statistiky.prohry += 1;
    }

    println!("statistiky: vyhry - {}, prohry - {}", statistiky.vyhry, statistiky.prohry);

    // ulozit statistiky do souboru
    statistiky.uloz_do_souboru();

    // aby se hnedka program nezavrel a pockal na input nejakej
    let mut x = String::new();
    let _ = io::stdin().read_line(&mut x);
}
