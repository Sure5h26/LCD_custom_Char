#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte chr[8];
int b=0;
byte store[16][8];
int s1=0;

void getChar()
{
  Serial.println("Enter the pattern of 1s and 0s for an 8x5 pixel display:");
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
  while(s1<=b)
  {
    for(int c=0;c<8;c++)
    {
      store[s1][c]=chr[c];
    }
    s1++;
  }
}

void setup()
{
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  getChar();
  lcd.setCursor(0, 0);
  lcd.print("Your character:");
  for(int i=0;i<(b+1);i++)
  {
    lcd.createChar(i, store[i]);
  }
  for(int a=0;a<(b+1);a++)
  {
    lcd.setCursor(a, 1);
    lcd.write(byte(a));
  }
  delay(100);
  b++;
  if(b==15 || s1==15)
  {
    b=0;
    s1=0;
  }
}
