const int analogPin = A0;
int sensorValue = 0;
int newValue = 0;

void setup() {
  Serial.begin(115200);
  pinMode(D6, OUTPUT);
}

void loop() {
  sensorValue = analogRead(analogPin);
  newValue = map(sensorValue, 0, 1023, 100, 1500);
  Serial.println(newValue);
  digitalWrite(D6, HIGH);
  delay(newValue);
  digitalWrite(D6, LOW);
  delay(50);
}