/**
 * Generator hodnot sinusove vlny pro PWM na ATmega16
 * 
 * Parametry:
 * - Frekvence krystalu: 14.7456 MHz
 * - Rozliseni PWM: 7 bitu (hodnoty 0-127)
 * - Pocet vzorku: 128
 * - Vysledna frekvence: 453 Hz
 * - RC filtr: R = 4.7k, C = 46nF (2 x 22nF)
 */

// konfigurace
const POCET_VZORKU = 128;
const ROZLISENI_BITU = 7;
const MAX_HODNOTA = Math.pow(2, ROZLISENI_BITU) - 1; // 127 pro 7-bit

// funkce pro generovani hodnot sinusove vlny
function generujSinusoveTabulky() {
  let hodnoty = [];
  const krok = (2 * Math.PI) / POCET_VZORKU;
  
  for (let i = 0; i < POCET_VZORKU; i++) {
    // vypocet sinusove hodnoty v rozsahu 0 az MAX_HODNOTA
    const sinHodnota = Math.sin(i * krok);
    const pwmHodnota = Math.round((sinHodnota + 1) * MAX_HODNOTA / 2);
    hodnoty.push(pwmHodnota);
  }
  
  return hodnoty;
}

// generovani a formatovani vystupu pro AVR assembler
function formatujProAVR(hodnoty) {
  let vystup = ";*************************** TABULKA SINUSU *************************************\n";
  vystup += "; Tabulka vzorku: jedna perioda navzorkovana na " + POCET_VZORKU + " vzorku\n";
  vystup += "; a kvantizovana s " + ROZLISENI_BITU + "-bitovym rozlisenim\n";
  vystup += ";***************************************************************************\n";
  vystup += "sine_tbl:";
  
  for (let i = 0; i < hodnoty.length; i += 2) {
    if (i % 16 === 0) {
      vystup += "\n.db ";
    } else if (i % 2 === 0) {
      vystup += ", ";
    }
    
    // zapis hodnoty, pokud jsme na konci, pridame jen jednu hodnotu
    if (i === hodnoty.length - 1) {
      vystup += hodnoty[i];
    } else {
      vystup += hodnoty[i] + "," + hodnoty[i + 1];
    }
  }
  
  return vystup;
}

// vypocet hodnot
const sinusoveHodnoty = generujSinusoveTabulky();
const avrKod = formatujProAVR(sinusoveHodnoty);

// vypis vysledku
console.log(avrKod);

// vypis parametru pro dokumentaci
console.log("\n\n// Parametry PWM generovani:");
console.log("// - Vysledna frekvence: 58053 / " + POCET_VZORKU + " = 453 Hz");