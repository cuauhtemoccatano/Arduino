#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C = lcd(0x27, 16, 2);

int sensor_pin = A0;       //Entrada Análoga Sensor Pin
int relay_pin = 7;         //Entrada digital Relay  Pin

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init()
  lcd.backlight();
  lcd.setBacklight(HIGH);