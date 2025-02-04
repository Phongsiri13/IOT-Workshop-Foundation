#define buzzerPin D1
#define pirPin D2
#define ledPin D3

int val = 0;
bool motionState = false;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  val = digitalRead(pirPin);

  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    alarm(500, 2000);
    delay(150);

    if (motionState == false) {
      Serial.println("Motion Detected");
      motionState = true;
    }
  } else {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
    delay(150);

    if (motionState == true) {
      Serial.println("No Motion");
      motionState = false;
    }
  }
}

void alarm(long duration, int freq) {
  tone(buzzerPin, freq);
  delay(duration);
  noTone(buzzerPin);
}