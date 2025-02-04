const int ledPin = D4;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char inRead = Serial.read();

    if (inRead == '1') {
      digitalWrite(ledPin, LOW); // Turn LED ON (LOW)
      Serial.println("put 1");
    } else if (inRead == '0') {
      digitalWrite(ledPin, HIGH); // Turn LED OFF (HIGH)
      Serial.println("put 0");
    } else if (inRead > '1') {
      Serial.println("Please enter 0 or 1 only");
    }
  }
  delay(100);
}