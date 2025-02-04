const int ledPin = D3;
const int ldrPin = D6;

void setup() {
  Serial.begin(112500);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);
}

void loop() {
  int ldrStatus = digitalRead(ldrPin);

  if (ldrStatus == 1) {
    digitalWrite(ledPin, HIGH);
    Serial.println("LDR --> Dark, LED --> ON");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("LDR --> Bright, LED --> OFF");
  }
}