#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte chr[8];

void getChar()
{
  Serial.println("Enter the pattern of 1s and 0s for an 8x5 pixel display:(ex.01110)");
  for (int i = 0; i < 8; i++)
  {
    while (!Serial.available())
    {
    }
    String s = Serial.readStringUntil('\n');
    s.trim();
    Serial.println(s);
    chr[i] = strtol(s.c_str(), NULL, 2);
  }
  setup();
}

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.createChar(0, chr);
}

void loop()
{
  getChar();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Your character:");
  lcd.setCursor(0, 1);
  lcd.write(byte(0));
  delay(1000);
}
