// C++ code
//
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

unsigned long seconds = 0;
unsigned long lastUpdate = 0; //time since last update

int randomPot;

//sprites
byte pot0[8] = {
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111
};

byte pot1[8] = {
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111
};

byte pot2[8] = {
  B10001,
  B10001,
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111
};

byte pot3[8] = {
  B10001,
  B10001,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte pot4[8] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};

byte potCover[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00100,
  B11111
};
//classe pot
class cookingPot
{
  private:
  	int positionPot;
  	int potLevel = 0;

  public:
  	void setupPot(int pos);
  	void raiseLevel();
};

//classe::metodo
void cookingPot::setupPot(int pos)
{
  positionPot = pos;
  lcd.setCursor(positionPot,0);
  lcd.write(5);
  lcd.setCursor(positionPot,1);
  lcd.write(0);
}

void cookingPot::raiseLevel()
{
  lcd.setCursor(positionPot,1);
  potLevel++;
  lcd.write(potLevel%5);
}
//fim class cookingPot

 cookingPot P1, P2, P3, P4, P5;

void setup()
{
  lcd.begin(16,2);
  
  //initialize random seed
  randomSeed(analogRead(0));
  
  //create sprites
  lcd.createChar(0, pot0);
  lcd.createChar(1, pot1);
  lcd.createChar(2, pot2);
  lcd.createChar(3, pot3);
  lcd.createChar(4, pot4);
  lcd.createChar(5, potCover);


  
  //create cooking pots
  P1.setupPot(0);
  P2.setupPot(2);
  P3.setupPot(4);
  P4.setupPot(6);
  P5.setupPot(8);
  
}

void loop()
{
  
  //timer
  lcd.setCursor(13, 0);
  seconds = millis()/1000;
  if (seconds < 10) lcd.print("  ");
  else if (seconds < 100) lcd.print(" ");
  lcd.print(seconds);
  unsigned long interval = random(100,600); //time between each update

  unsigned long timeUntilUpdate = millis();
  if (timeUntilUpdate - lastUpdate >= interval)
  {
    lastUpdate = timeUntilUpdate;
    randomPot = random(1,6);
    if(randomPot == 1) 	 P1.raiseLevel();
    else if(randomPot == 2)P2.raiseLevel();
    else if(randomPot == 3)P3.raiseLevel();
    else if(randomPot == 4)P4.raiseLevel();
    else if(randomPot == 5)P5.raiseLevel();
  }
  
  

}
