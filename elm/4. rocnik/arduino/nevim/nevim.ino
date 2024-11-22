#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SensirionI2CSgp41.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

int senzurek = A0;

SensirionI2CSgp41 sgp41;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

uint16_t conditioning_s = 10;

static const int digit_array[16][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 0, 0, 1, 1},  // 9
  {1, 1, 1, 0, 1, 1, 1},  // A
  {0, 0, 1, 1, 1, 1, 1},  // B
  {1, 0, 0, 1, 1, 1, 0},  // C
  {0, 1, 1, 1, 1, 0, 1},  // D
  {1, 0, 0, 1, 1, 1, 1},  // E
  {1, 0, 0, 0, 1, 1, 1},  // F
};

int analogovaHodnota;
int zobrazovanaHodnota;

void setup() {

    Wire.begin();
    Serial.begin(9600);
    Serial.println("Scanning...");
    for (uint8_t i = 1; i < 127; i++) {
        Wire.beginTransmission(i);
        if (Wire.endTransmission() == 0) {
            Serial.print("Found device at: 0x");
            Serial.println(i, HEX);
        }
    }

    display.begin(SSD1306_SWITCHCAPVCC, 0x59);
    display.display();

    uint16_t error;
    char errorMessage[256];

    sgp41.begin(Wire);

    uint8_t serialNumberSize = 3;
    uint16_t serialNumber[serialNumberSize];

    error = sgp41.getSerialNumber(serialNumber);

    if (error) {
        Serial.print("Error trying to execute getSerialNumber(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("SerialNumber:");
        Serial.print("0x");
        for (size_t i = 0; i < serialNumberSize; i++) {
            uint16_t value = serialNumber[i];
            Serial.print(value < 4096 ? "0" : "");
            Serial.print(value < 256 ? "0" : "");
            Serial.print(value < 16 ? "0" : "");
            Serial.print(value, HEX);
        }
        Serial.println();
    }

    uint16_t testResult;
    error = sgp41.executeSelfTest(testResult);
    if (error) {
        Serial.print("Error trying to execute executeSelfTest(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else if (testResult != 0xD400) {
        Serial.print("executeSelfTest failed with error: ");
        Serial.println(testResult);
    }
}

void loop() {
  uint16_t error;
  char errorMessage[256];
  uint16_t defaultRh = 0x8000;
  uint16_t defaultT = 0x6666;
  uint16_t srawVoc = 0;
  uint16_t srawNox = 0;

  delay(1000);

    if (conditioning_s > 0) {
        // During NOx conditioning (10s) SRAW NOx will remain 0
        error = sgp41.executeConditioning(defaultRh, defaultT, srawVoc);
        conditioning_s--;
    } else {
        // Read Measurement
        error = sgp41.measureRawSignals(defaultRh, defaultT, srawVoc, srawNox);
    }

    if (error) {
        Serial.print("Error trying to execute measureRawSignals(): ");
        errorToString(error, errorMessage, 256);
        Serial.println(errorMessage);
    } else {
        Serial.print("SRAW_VOC: ");
        Serial.print(srawVoc);
        Serial.print("\t");
        Serial.print("SRAW_NOx: ");
        Serial.println(srawNox);

        // Display VOC and NOx on OLED
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(0, 0);
        display.print("SRAW_VOC: ");
        display.println(srawVoc);
        display.print("SRAW_NOx: ");
        display.println(srawNox);
        display.display();
    }
}