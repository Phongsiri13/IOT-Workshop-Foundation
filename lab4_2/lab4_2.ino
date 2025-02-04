void setup() {
  Serial.begin(9600);
  delay(100);
  Serial.println("Fill your name and then press enter");
}

void loop() {
  if (Serial.available()) {
    String name = Serial.readString();
    Serial.print("My name is ");
    Serial.println(name);
  }
}