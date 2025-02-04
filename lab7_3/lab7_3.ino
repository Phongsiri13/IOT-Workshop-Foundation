#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11

LiquidCrystal_I2C lcd(0x27, 16, 2);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();

  lcd.begin();
  lcd.backlight();

  lcd.print("DHT11 TEST");
}

void loop() {
  delay(2000);

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  if (isnan(t) || isnan(h)) {
    lcd.clear();
    lcd.print("DHT Failed");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.setCursor(7, 0);
    lcd.print(t);
    lcd.setCursor(13, 0);
    lcd.print("C");

    lcd.setCursor(0, 1);
    lcd.print("Humid: ");
    lcd.print(h);
    lcd.setCursor(14, 1);
    lcd.print("%");
  }
  delay(1000);
}