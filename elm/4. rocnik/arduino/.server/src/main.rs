use serde::{ Deserialize, Serialize };
use std::error::Error;
use std::io::{ BufRead, BufReader };
use std::net::TcpListener;

#[derive(Debug, Serialize, Deserialize)]
struct Data {
    from: String,
    timestamp: String,
    teplota: String,
    vlhkost: String,
    tlak: String,
    co2: String,
}

fn main() -> Result<(), Box<dyn Error>> {
    let listener = TcpListener::bind("10.12.80.2:80")?;
    println!("posloucham port 80...");

    for stream in listener.incoming() {
        let stream = stream?;
        let mut reader = BufReader::new(stream);
        let mut buffer = String::new();

        reader.read_line(&mut buffer)?;
        // println!("co prislo: {}", buffer);

        let data: Data = serde_json::from_str(&buffer)?;
        // println!("data: {:?}", data);

        println!("----------------------");
        println!("odkud: {}", data.from);
        println!("kdy: {}", data.timestamp);
        println!("teplota: {}°C", data.teplota);
        println!("vlhkost: {}", data.vlhkost);
        println!("tlak: {}", data.tlak);
        println!("co2: {}", data.co2);
        println!("----------------------");
    }

    Ok(())
}
