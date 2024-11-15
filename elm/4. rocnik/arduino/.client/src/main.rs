use serde::Serialize;
use std::error::Error;
use std::io::Write;
use std::net::TcpStream;
use rand::Rng;
use std::thread;
use std::time::Duration;

#[derive(Debug, Serialize)]
struct Data {
    from: String,
    timestamp: String,
    teplota: String,
    vlhkost: String,
    tlak: String,
    co2: String,
}

fn send_json_to_server(data: &Data) -> Result<(), Box<dyn Error>> {
    let mut prenos = TcpStream::connect("10.12.80.2:80")?;
    let json = serde_json::to_string(data)? + "\n";
    prenos.write_all(json.as_bytes())?;
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let mut rng = rand::thread_rng();

    loop {
        let data = Data {
            from: "sklep".to_string(),
            timestamp: "2023-10-10T10:00:00Z".to_string(),
            teplota: format!("{:.1}", rng.gen_range(15.0..30.0)),
            vlhkost: format!("{}", rng.gen_range(30..70)),
            tlak: format!("{}", rng.gen_range(980..1050)),
            co2: format!("{}", rng.gen_range(350..450)),
        };

        send_json_to_server(&data)?;
        println!("poslany data: {:?}", data);

        thread::sleep(Duration::from_secs(10));
    }
}
