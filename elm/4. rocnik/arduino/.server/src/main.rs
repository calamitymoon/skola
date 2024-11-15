use serde::{ Deserialize, Serialize };
use std::error::Error;
use std::io::{ BufRead, BufReader, Write };
use std::net::TcpListener;
use std::fs::File;

#[derive(Debug, Serialize, Deserialize)]
struct Data {
    from: String,
    timestamp: String,
    teplota: String,
    vlhkost: String,
    tlak: String,
    co2: String,
}

fn vygenerovat_html(data: &Data) -> String {
    format!(
        r#"<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Data ze senzorů</title>
    <meta http-equiv="refresh" content="10">
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0-alpha1/dist/css/bootstrap.min.css" rel="stylesheet">
    <style>
        body {{
            display: flex;
            justify-content: center;
            align-items: center;
            min-height: 100vh;
            margin: 0;
            background-color: #f8f9fa;
        }}
        .card {{
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            border-radius: 12px;
        }}
    </style>
</head>
<body>
    <div class="card p-4">
        <h2 class="text-center mb-4">Sensor Data</h2>
        <ul class="list-group list-group-flush">
            <li class="list-group-item"><strong>Odkud:</strong> <span id="from">{from}</span></li>
            <li class="list-group-item"><strong>Kdy:</strong> <span id="timestamp">{timestamp}</span></li>
            <li class="list-group-item"><strong>Teplota:</strong> <span id="teplota">{teplota}°C</span></li>
            <li class="list-group-item"><strong>Vlhkost:</strong> <span id="vlhkost">{vlhkost}%</span></li>
            <li class="list-group-item"><strong>Tlak:</strong> <span id="tlak">{tlak} Pa</span></li>
            <li class="list-group-item"><strong>CO2:</strong> <span id="co2">{co2} ppm</span></li>
        </ul>
    </div>
</body>
</html>
"#,
        from = data.from,
        timestamp = data.timestamp,
        teplota = data.teplota,
        vlhkost = data.vlhkost,
        tlak = data.tlak,
        co2 = data.co2
    )
}

fn ulozit_html_do_souboru(html: &str, file_name: &str) -> Result<(), Box<dyn Error>> {
    let mut file = File::create(file_name)?;
    file.write_all(html.as_bytes())?;
    Ok(())
}

fn main() -> Result<(), Box<dyn Error>> {
    let listener = TcpListener::bind("192.168.0.250:80")?;
    println!("posloucham na portu 80...");

    for stream in listener.incoming() {
        let stream = stream?;
        let mut reader = BufReader::new(stream);
        let mut buffer = String::new();
        reader.read_line(&mut buffer)?;
        let data: Data = serde_json::from_str(&buffer)?;
        let html = vygenerovat_html(&data);
        ulozit_html_do_souboru(&html, "index.html")?;
    }

    Ok(())
}
