#include <SPI.h>
#include <Ethernet.h>
#include <ArduinoJson.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress server(192, 168, 129, 43);
int port = 7878;
EthernetClient client;

float temperature = 22.5;
float humidity = 45.2;
float pressure = 1013.25;
int co2 = 420;

void setup() {
    Serial.begin(9600);
    delay(1000);
    Serial.println("zacinam...");
    
    // if (Ethernet.begin(mac) == 0) {
    //     Serial.println("Failed to configure Ethernet using DHCP");
    //     IPAddress ip(10, 12, 69, 51);
    //     Ethernet.begin(mac, ip);
    // }
    
    delay(1000);
    Serial.print("IP adresa Arduina: ");
    Serial.println(Ethernet.localIP());
}

void loop() {
    temperature = random(150, 300) / 10.0;  // 15.0 - 30.0
    humidity = random(30, 70);              // 30 - 70
    pressure = random(980, 1050);           // 980 - 1050
    co2 = random(350, 450);                 // 350 - 450
    
    odeslatNaServer();
    delay(10000);
}

void odeslatNaServer() {
    Serial.println("pripojovani...");
    
    if (client.connect(server, port)) {
        Serial.println("pripojeni se povedlo");
        
        StaticJsonDocument<256> json;
        
        json["odkud"] = "Místnost 1";
        json["timestamp"] = String(millis());
        json["teplota"] = String(temperature, 1);
        json["vlhkost"] = String(humidity);
        json["tlak"] = String(pressure);
        json["co2"] = String(co2);
        
        String jsonString;
        serializeJson(json, jsonString);
        
        jsonString += "\n";
        
        client.print(jsonString);
        
        Serial.print("odeslano: ");
        Serial.print(jsonString);
        
        client.stop();
        Serial.println("pripojeni uzavreno");
    } else {
        Serial.println("pripojeni selhalo");
    }
}