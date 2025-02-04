void setup() {
  pinMode(D2, INPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  int buttonStatus = digitalRead(D2);
  if (buttonStatus == 0) {
    digitalWrite(D6, HIGH);
  } else {
    digitalWrite(D6, LOW);
  }
  delay(100);
}