const int ledPin = D4;
int timeOn = 1000;
int timeOff = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(ledPin, LOW);  // Turn the LED ON
  Serial.println(1);        // Print 1 to Serial Monitor (LED is ON)
  delay(timeOn);            // Wait for timeOn milliseconds

  digitalWrite(ledPin, HIGH); // Turn the LED OFF
  Serial.println(0);        // Print 0 to Serial Monitor (LED is OFF)
  delay(timeOff);           // Wait for timeOff milliseconds
}