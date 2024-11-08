#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9

int senzurek = A0;

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

int analogovaHodnota;
int zobrazovanaHodnota;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
}

void loop() {
  display.clearDisplay();
  int analogovaHodnota = analogRead(senzurek);
  
  Serial.println(analogovaHodnota);
  
  render_digits(0, 0, 18, analogovaHodnota, WHITE);
  display.display();
  delay(1000);
}

void render_digits(uint8_t pos_x, uint8_t pos_y, uint8_t spacing_x, int value, uint8_t color) {
  int digits[3] = {0, 0, 0};
  int num_digits = 0;

  if (value > 99) {
    digits[0] = (value / 100) % 10;
    digits[1] = (value / 10) % 10;
    digits[2] = value % 10;
    num_digits = 3;
  } else if (value > 9) {
    digits[0] = (value / 10) % 10;
    digits[1] = value % 10;
    num_digits = 2;
  } else {
    digits[0] = value % 10;
    num_digits = 1;
  }

  for (int i = 0; i < num_digits; i++) {
    render_digit(pos_x + (spacing_x * i), pos_y, digits[i], color);
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