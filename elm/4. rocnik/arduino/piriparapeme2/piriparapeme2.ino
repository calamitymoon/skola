#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_BME280.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

int senzurek = A0;

Adafruit_BME280 bme; // I2C
Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

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

float temperature = 0.0;
float humidity = 0.0;
float pressure = 0.0;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  Serial.println(F("BME280 Sensor event test"));

  display.display();
  display.clearDisplay();

  if (!bme.begin()) {
    Serial.println(F("Could not find a valid BME280 sensor, check wiring!"));
    while (1) delay(10);
  }

  bme_temp->printSensorDetails();
  bme_pressure->printSensorDetails();
  bme_humidity->printSensorDetails();
}

void loop() {
  sensors_event_t temp_event, pressure_event, humidity_event;
  bme_temp->getEvent(&temp_event);
  bme_humidity->getEvent(&humidity_event);
  bme_pressure->getEvent(&pressure_event);

  Serial.println("Teplota: ");
  Serial.print(temp_event.temperature);
  Serial.println("Vlhkost: ");
  Serial.print(humidity_event.relative_humidity);
  Serial.println("Tlak: ");
  Serial.print(pressure_event.pressure);

  Serial.println();
  display.clearDisplay();

  render_digits(0, 0, 18, temp_event.temperature, WHITE); // Top row
  render_digits(0, 20, 18, humidity_event.relative_humidity, WHITE);   // Middle row
  render_digits(0, 40, 18, pressure_event.pressure, WHITE);   // Bottom row

  display.display();
  delay(1000);
}

float extractNumericValue(String input) {
  String numericPart = "";
  for (char c : input) {
    if (isDigit(c) || c == '.' || c == '-') {
      numericPart += c;
    }
  }
  return numericPart.toFloat();
}

void render_digits(uint8_t pos_x, uint8_t pos_y, uint8_t spacing_x, float value, uint8_t color) {
  String valueString = String(value, 2); // Convert value to string with 2 decimal places
  int len = valueString.length();

  for (int i = 0; i < len; i++) {
    char c = valueString[i];
    if (c == '.') {
      display.fillCircle(pos_x + (spacing_x * i) + 3, pos_y + 10, 2, color); // Render decimal point
    } else if (isDigit(c)) {
      render_digit(pos_x + (spacing_x * i), pos_y, c - '0', color); // Render digits
    }
  }
}

void render_digit(uint8_t pos_x, uint8_t pos_y, uint8_t digit, uint8_t color) {                  
  for (uint8_t i = 0; i < 7; i++) {
    bool seg_on = digit_array[digit][i];
    if (seg_on) {
      switch (i) {
        case 0:
          display.fillRoundRect(2 + pos_x, 0 + pos_y, 9, 3, 2, color); // SEG a
          break;
        case 1:
          display.fillRoundRect(10 + pos_x, 2 + pos_y, 3, 9, 2, color); // SEG b
          break;
        case 2:
          display.fillRoundRect(10 + pos_x, 12 + pos_y, 3, 9, 2, color); // SEG c
          break;
        case 3:
          display.fillRoundRect(2 + pos_x, 20 + pos_y, 9, 3, 2, color); // SEG d
          break;
        case 4:
          display.fillRoundRect(0 + pos_x, 12 + pos_y, 3, 9, 2, color); // SEG e
          break;
        case 5:
          display.fillRoundRect(0 + pos_x, 2 + pos_y, 3, 9, 2, color); // SEG f
          break;
        case 6:
          display.fillRoundRect(2 + pos_x, 10 + pos_y, 9, 3, 2, color); // SEG g
          break;
      }
    }
  }
}
