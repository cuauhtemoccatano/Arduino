#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C  lcd(0x27, 16, 2);

int sensor_pin = A0;       //Entrada Análoga Sensor Pin
int relay_pin = 2;         //Entrada Digital Relay  Pin

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.init();
  lcd.backlight();
  lcd.setBacklight(HIGH);
  pinMode(sensor_pin, INPUT);
   pinMode(relay_pin, OUTPUT);
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);//
  Serial.print("Sensor_data:");
  Serial.print(sensor_data);
  Serial.print("\t | ");
  
  if(sensor_data > 950)
  {
    Serial.println("No moisture, Soil is dry");
    digitalWrite(relay_pin, HIGH);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Humedad 0%");
    lcd.setCursor(0,0);
    lcd.print("Riego ON");
  }}
  else if(sensor_data >= 550 && sensor_data <= 950)
  {
    Serial.println("There is some moisture, Soil is medium");
    digitalWrite(relay_pin, HIGH);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Humedad 50%");
    lcd.setCursor(0,0);
    lcd.print("Riego ON");
  }
  else if(sensor_data < 550)
  {
    Serial.println("Soil is wet");
    digitalWrite(relay_pin, LOW);
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("Humedad 100%");
    lcd.setCursor(0,0);
    lcd.print("Riego OFF");
  }

  delay(5000);
}
