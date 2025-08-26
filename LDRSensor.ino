#include <LiquidCrystal.h>

int sensorPin = A0;
int sensorValue = 0;

const int rs = 13, en = 12, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  Serial.begin(9600);

  lcd.begin(20, 4);
  lcd.clear();
  lcd.print("Check the brightness");
}

void loop() {
  sensorValue = analogRead(sensorPin);

  lcd.setCursor(1, 1);
  if(sensorValue <= 400){
    Serial.print("It's dark.Value is = ");
    Serial.println(sensorValue);

    lcd.print("It's dark.Value is = ");
    lcd.println(sensorValue);
  } else if (sensorValue > 400) {
    Serial.print("Too Bright.Value is = ");
    Serial.println(sensorValue);

    lcd.print("Too Bright.Value is = ");
    lcd.println(sensorValue);
  };

  delay(200);
}
