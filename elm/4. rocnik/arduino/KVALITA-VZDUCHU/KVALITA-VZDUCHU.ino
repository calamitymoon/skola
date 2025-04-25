#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Arduino.h>
#include <BME280_Arduino_I2C.h>
#include <MQ135.h>

BME280_Arduino_I2C bme(0x77);

#define pinA A0

MQ135 senzorMQ = MQ135(PIN_A0);

void setup() {
  Serial.begin(9600);

  if (bme.begin() == 0) {
        Serial.println("BME280 initialized");
    } else {
        /*
            Returning code 1: Wire is not available
            Returning code 2: Device has not been found
        */
        Serial.println("BME280 failed to initialize");
    }
    delay(10);

  for(;;) {
    BME280Data* data = bme.read();
    float co2 = analogRead(PIN_A0);

    Serial.print("Teplota:  ");
    Serial.print(data->temperature);
    Serial.println("°C");

    Serial.print("Vlhkost:  ");
    Serial.print(data->humidity);
    Serial.println("%");

    Serial.print("CO2:      ");
    Serial.print(co2);
    Serial.println(" ppm");

    Serial.print("Tlak:     ");
    Serial.print(data->pressure);
    Serial.println("Pa");
    
    Serial.println("\n----------------------------------\n");
    delay(1000);
  }
}

void loop() {
}
