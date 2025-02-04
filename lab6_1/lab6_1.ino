const int buttonPin = D1;
volatile bool interruptFlag = false;

void ICACHE_RAM_ATTR handleInterrupt() {
  interruptFlag = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, FALLING);
}

void loop() {
  if (interruptFlag) {
    Serial.println("Interrupt Triggered!");
    interruptFlag = false;
  }
}