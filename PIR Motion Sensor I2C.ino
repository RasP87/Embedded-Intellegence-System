#include <LiquidCrystal_I2C.h>

int pirSensorPin = 12; 
int ledPin = 13; 
LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  pinMode(pirSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

  lcd.init(); 
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("   Rizza   ");
  lcd.setCursor(0, 1);
  lcd.print("   Dzalfa  ");
  delay(3000);
  lcd.clear();

  Serial.begin(9600);
}

void loop() {
  int pirValue = digitalRead(pirSensorPin);
  
  if (pirValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    lcd.clear();
    lcd.setCursor(0, 0); 
    lcd.print("Motion detected!");
    Serial.println("Motion detected!");
  } 

  else {
    digitalWrite(ledPin, LOW);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   No motion   "); 
    lcd.setCursor(0, 1);
    lcd.print("   detected!   "); 
  }
  delay(1000);
}
