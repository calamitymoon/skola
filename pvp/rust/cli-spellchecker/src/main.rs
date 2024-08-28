/*
    This code uses a list of English words from a public domain source.
    The original repository is licensed under the Unlicense, which allows for
    free use, modification, and distribution. For more information, visit:
    https://unlicense.org/

    The original repository can be found at:
    https://github.com/dwyl/english-words/
*/

use std::env;
use std::fs::File;
use std::io::{ self, BufRead };
use std::path::Path;
use std::collections::HashSet;
use tokio::runtime::Runtime;

async fn load_words(url: &str) -> Result<HashSet<String>, reqwest::Error> {
    let response = reqwest::get(url).await?.text().await?;
    let mut words = HashSet::new();
    for line in response.lines() {
        let word = line.trim().to_string();
        if !word.is_empty() {
            words.insert(word);
        }
    }
    Ok(words)
}

fn check_spelling(filename: &str, words: &HashSet<String>) -> io::Result<()> {
    let path = Path::new(filename);
    let file = File::open(&path)?;
    let reader = io::BufReader::new(file);

    //  kazdy radek v souboru zkontroluje a vypise slova, ktera nejsou ve words.txt (line 55)
    for (line_number, line) in reader.lines().enumerate() {
        let line = line?;
        for word in line.split_whitespace() {
            // odstraneni nealphanumerickych znaku a prevedeni na lowercase
            let cleaned_word = word.trim_matches(|c: char| !c.is_alphanumeric()).to_lowercase();
            // pokud slovo neni v words.txt, tak se vypise
            if !words.contains(&cleaned_word) && !cleaned_word.is_empty() {
                println!("potencional typo | line {}: '{}'", line_number + 1, word);
            }
        }
    }

    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().collect();

    //  jestli je pocet argumentu vetsi nez 1:
    if args.len() != 2 {
        eprintln!("usage:\n- spellcheck <file>");
        return;
    }

    let rt = Runtime::new().unwrap();
    let words = match
        rt.block_on(
            load_words("https://raw.githubusercontent.com/dwyl/english-words/master/words.txt")
        )
    {
        //  pokud se nepodari nacist slova, tak se vypise chyba
        Ok(dict) => dict,
        Err(e) => {
            eprintln!("error loading words: {}", e);
            return;
        }
    };

    //  pokud se nepodari zkontrolovat pravopis, tak se vypise chyba
    if let Err(e) = check_spelling(&args[1], &words) {
        eprintln!("error reading file: {}", e);
    }
}
