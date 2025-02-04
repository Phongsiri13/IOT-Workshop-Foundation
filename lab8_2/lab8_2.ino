#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define TRIG_PIN 7
#define ECHO_PIN 6
#define RED_PIN 3
#define GREEN_PIN 4

long duration, distance;

void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  lcd.begin();
  lcd.backlight();
  lcd.home();

  lcd.print("Check Distance");
  lcd.setCursor(0, 1);
  lcd.print("Ready");

  lcd.clear();
  delay(2000);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;

  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm");

  if (distance <= 15) {
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(RED_PIN, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Safe");
  } else {
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(RED_PIN, HIGH);
    lcd.setCursor(8, 1);
    lcd.print("Stop");
  }
  delay(500);
}