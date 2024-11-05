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

// tocici cisla
int rotateNumbers() {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 4; j++) {
      display.clearDisplay();
      display.setTextColor(WHITE);
      display.setCursor(0, 10);
      display.setRotation(j);
      display.println(i);
      display.display();  
      delay(250);
    }
  }
}

// SSD1306_BLACK, SSD1306_WHITE, 
void colorPrompt() {
  uint16_t color = SSD1306_WHITE;
  display.clearDisplay();
  display.setTextColor(color);
  display.setCursor(0, 10);
  display.println(" testik");
  display.display();
  delay(250);
}

bool viditelnost = true;

void vidisme() {
  viditelnost = !viditelnost;
}

void blinkingText() {
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setCursor(0, 10);
  
  if (viditelnost == true) {
    display.println(" ted me vidis");
  } else {
    display.setTextColor(BLACK);
    display.println(" a ted ne");
  }
  display.display();
  delay(250);
}

void setup() {
  Serial.begin(9600);

  if(!display.begin(SSD1306_SWITCHCAPVCC)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  display.display();
  delay(2000);

  display.clearDisplay();
}

void loop() {
  // rotateNumbers();

  // colorPrompt();

  // vidisme();
  // blinkingText();
  // delay(250);

  // segDisplay();
}
