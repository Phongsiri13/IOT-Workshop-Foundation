//NodeMCU Master
#include <SPI.h>
#define CS 10

void setup() {
  pinMode(CS, OUTPUT);

  digitalWrite(CS, HIGH);
  SPI.begin();

  Serial.begin(115200);
  delay(100);
}

void loop() {
  digitalWrite(CS, LOW);
  byte received = SPI.transfer(0x02);

  digitalWrite(CS, HIGH);
  Serial.print("Received from Slave: ");
  Serial.println(received);

  delay(1000);
}