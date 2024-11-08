#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define OLED_DC     8
#define OLED_CS     10
#define OLED_RESET  9
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &SPI, OLED_DC, OLED_RESET, OLED_CS);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16
static const unsigned char PROGMEM logo_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };

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

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display();
}

void loop() {
  for (int cnt = 0; cnt < 4095; cnt++) {
    display.clearDisplay();
    render_digits(0, 0, 18, cnt, WHITE);
    display.display();
  }
}

void render_digits(uint8_t pos_x, uint8_t pos_y, uint8_t spacing_x, uint16_t digit, uint8_t color) {
  uint8_t digit_array[] = { (digit >> 8) & 0xF, (digit >> 4) & 0xF, digit & 0xF };
  
  if (digit > 0xFF) {
    render_digit(pos_x, pos_y, digit_array[0], color);
  }

  if (digit > 0xF) {
    render_digit(pos_x + spacing_x, pos_y, digit_array[1], color);
  }

  render_digit(pos_x + (spacing_x * 2), pos_y, digit_array[2], color);
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
      seg_on = false;
    }
  }
}