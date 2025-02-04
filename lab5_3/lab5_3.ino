const int buttonPin = D1;
volatile bool interruptFlag = false;
volatile int lastState = HIGH;

void ICACHE_RAM_ATTR handleInterrupt() {
  interruptFlag = true;
}

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleInterrupt, CHANGE);
}

void loop() {
  if (interruptFlag) {
    int currentState = digitalRead(buttonPin);
    if (currentState != lastState) {
      Serial.print("State changed to: ");
      Serial.println(currentState == HIGH ? "HIGH" : "LOW");
      lastState = currentState;
    }
    interruptFlag = false;
  }
}