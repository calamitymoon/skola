void setup() {
  pinMode(PIN_A0, OUTPUT);
}

void loop() {
  for (int silaZareni = 0; silaZareni <= 255; silaZareni++) {
    analogWrite(PIN_A0, silaZareni);
    delay(100);
  }
  
  for (int silaZareni = 255; silaZareni >= 0; silaZareni--) {
    analogWrite(PIN_A0, silaZareni);
    delay(100);
  }
}