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

const byte segmentDisplay[] = {
    0b11000000, // '0'
    0b11111001, // '1'
    0b10100100, // '2'
    0b10110000, // '3'
    0b10011001, // '4'
    0b10010010, // '5'
    0b10000010, // '6'
    0b11111000, // '7'
    0b10000000, // '8'
    0b10010000, // '9'
    0b10001000, // 'A'
    0b10000011, // 'B'
    0b11000110, // 'C'
    0b10100001, // 'D'
    0b10000110, // 'E'
    0b10001110  // 'F'
};

void vykreslitZnak(char znak) {
  byte segmenty;

  // kontrola jaky znak je predanej funkci (podle toho vybira segmenty z arraye segmentDisplay)
  if (znak >= '0' && znak <= '9') {
    // indexovani pomoci ascii hodnoty
    segmenty = segmentDisplay[znak - '0'];
  } else if (znak >= 'A' && znak <= 'F') {
    segmenty = segmentDisplay[znak - 'A' + 10];
  } else { return; }

  vykreslitSegment(segmenty & 0b01000000, 10, 0, 30, 5);  // A
  vykreslitSegment(segmenty & 0b00100000, 40, 5, 5, 30);  // B
  vykreslitSegment(segmenty & 0b00010000, 40, 40, 5, 30); // C
  vykreslitSegment(segmenty & 0b00001000, 10, 70, 30, 5); // D
  vykreslitSegment(segmenty & 0b00000100, 5, 40, 5, 30);  // E
  vykreslitSegment(segmenty & 0b00000010, 5, 5, 5, 30);   // F
  vykreslitSegment(segmenty & 0b00000001, 10, 35, 30, 5); // G
}

void vykreslitSegment(bool stav, int x, int y, int sirka, int vyska) {
  if (stav) {
    display.fillRect(x, y, sirka, vyska, SSD1306_WHITE);
  }
}

// void segDisplay() {
//   for (int i = 0; i < 16; i++) {
//     display.clearDisplay();
//     display.setTextColor(WHITE);
//     display.setCursor(0, 10);
//     display.print("segmenty: ");
//     display.print(segmentDisplay[i], BIN);  // binarni cislo
//     display.display();
//     delay(1000);
//   }
// }

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
  vykreslitZnak("A");
}
