//Arduino UNO R3 Slave
#include <Wire.h>

void setup() {
  pinMode(13, OUTPUT);
  Wire.begin(43);
}

void loop() {
  Wire.onReceive(myHandler);
  delay(300);
}

void myHandler(int numByte) {
  while (Wire.available()) {
    char c = Wire.read();
    if (c == '1') {
      digitalWrite(13, HIGH);
    } else if (c == '0') {
      digitalWrite(13, LOW);
    }
  }
}