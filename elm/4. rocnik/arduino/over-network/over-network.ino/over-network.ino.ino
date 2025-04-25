#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 177);              // Statická IP (měň dle své sítě)
IPAddress gateway(192, 168, 1, 1);           // Gateway
IPAddress subnet(255, 255, 255, 0);          // Maska podsítě
IPAddress server(192, 168, 129, 35);         // Server IP (měň dle potřeby)
int port = 7878;

EthernetClient client;

float temperature = 22.5;
float humidity = 45.2;
float pressure = 1013.25;
int co2 = 420;
int mistnost = 0;

void setup() {
    Serial.begin(9600);
    delay(1000);
    Serial.println("zacinam...");

    // pokus o dhcp
    if (Ethernet.begin(mac) == 0) {
        Serial.println("DHCP selhalo, nastavuji statickou IP");
        Ethernet.begin(mac, ip, gateway, subnet);
    }

    // pokus o nacteni sd karty
    if (!SD.begin(4)) {
        Serial.println("sd karta << nenactena");
        while (1);
    }
    Serial.println("sd karta >> nactena");

    delay(1000);
    Serial.print("IP adresa Arduina: ");
    Serial.println(Ethernet.localIP());
}

void loop() {
    temperature = random(150, 300) / 10.0;  // 15.0 - 30.0
    humidity = random(30, 70);              // 30 - 70
    pressure = random(980, 1050);           // 980 - 1050
    co2 = random(350, 450);                 // 350 - 450
    mistnost = random(1, 10);               // 1 - 10

    odeslatNaServer();
    delay(10000);
}

void odeslatNaServer() {
    String dataServer   = String(mistnost) + "," + millis() + "," + temperature + "," + humidity + "," + pressure + "," + co2 + "," + "senzor";
    String dataPamet    = String(mistnost) + "," + millis() + "," + temperature + "," + humidity + "," + pressure + "," + co2;

    if (client.connect(server, port)) {
        Serial.println("[+] pripojeni");

        client.print(dataServer);

        Serial.print("odeslano: ");
        Serial.print(dataServer);

        client.stop();
    } else {
        Serial.println("[-] pripojeni");

        ulozitOffline(dataPamet);
    }
}

void ulozitOffline(String dataPamet) {
    File soubor = SD.open("offline.txt", FILE_WRITE);
    if (soubor) {
        soubor.println(dataPamet);
        soubor.close();
        Serial.println("[+] offline");
    } else {
        Serial.println("nemuzu ulozit data do offline.txt");
    }
}
