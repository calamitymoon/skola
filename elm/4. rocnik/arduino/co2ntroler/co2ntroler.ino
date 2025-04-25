#include <SPI.h>
#include <Ethernet.h>
#include <SD.h>
#include <Wire.h>
#include <BME280_Arduino_I2C.h>
#include <MQ135.h>

#define PIN_SD 4
#define PIN_MQ A0

const char* mistnost = "pocitacovna";

byte mac[]     = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip     (192, 168, 1, 177);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet (255, 255, 255, 0);
IPAddress server (77, 95, 40, 244);
const int port = 7878;

EthernetClient client;
BME280_Arduino_I2C bme(0x77);
MQ135 senzorMQ(PIN_MQ);

void setup() {
  Serial.begin(9600);
  // if (bme.begin() != 0) Serial.println(F("BME280 init fail"));
  // else Serial.println(F("BME280 OK"));

  if (Ethernet.begin(mac) == 0) {
    // Serial.println(F("DHCP fail, static IP"));
    Ethernet.begin(mac, ip, gateway, subnet);
  }

  // if (!SD.begin(PIN_SD)) {
  //   Serial.println(F("SD fail"));
  //   while (1);
  // }

  // Serial.print(F("IP: "));
  // Serial.println(Ethernet.localIP());
}

void loop() {
  BME280Data* data = bme.read();
  float temp = data->temperature;
  int hum = data->humidity;
  float pres = data->pressure;
  int co2 = analogRead(PIN_MQ);

  // Serial.print(F("T: ")); Serial.print(temp); Serial.print(F("°C  "));
  // Serial.print(F("H: ")); Serial.print(hum); Serial.print(F("%  "));
  // Serial.print(F("CO2: ")); Serial.print(co2); Serial.print(F("ppm  "));
  // Serial.print(F("P: ")); Serial.print(pres); Serial.println(F("Pa"));

  odeslatNaServer(temp, hum, pres, co2);
  delay(3000);
}

void odeslatNaServer(float t, int h, float p, int co2) {
  String ms = String(mistnost);
  String payload = ms + "," + millis() + "," + t + "," + h + "," + p + "," + co2 + ",senzor";
  String offline = ms + "," + millis() + "," + t + "," + h + "," + p + "," + co2;

  if (client.connect(server, port)) {
    client.print(payload);
    client.stop();
    // Serial.println(F("[+] Odeslano na server"));
  } else {
    // Serial.println(F("[-] Server nedostupny"));
    ulozitOffline(offline);
  }
}

void ulozitOffline(const String& z) {
  File f = SD.open("offline.txt", FILE_WRITE);
  if (f) {
    f.println(z);
    f.close();
    // Serial.println(F("[+] Ulozeno offline"));
  } else {
    // Serial.println(F("[-] Chyba zapisu na SD"));
  }
}
