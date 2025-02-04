#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
byte heart[8] = {0x00, 0x00, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00};

void setup() {
  lcd.begin();
}

void loop() {
  lcd.backlight();
  lcd.display();
  lcd.home();

  delay(1000);
  lcd.print("we love");
  delay(2000);

  lcd.setCursor(0, 1);
  lcd.print("IoT");
  delay(2000);

  lcd.createChar(0, heart);
  lcd.setCursor(4, 1);
  lcd.write(0);
  delay(2000);

  for (int i = 0; i < 15; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  for (int i = 0; i < 32; i++) {
    lcd.scrollDisplayRight();
    delay(200);
  }

  for (int i = 0; i < 16; i++) {
    lcd.scrollDisplayLeft();
    delay(200);
  }

  delay(2000);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(1000);

  lcd.clear();
  delay(1000);
  lcd.noDisplay();
  delay(1000);
  lcd.noBacklight();
  delay(2000);
}