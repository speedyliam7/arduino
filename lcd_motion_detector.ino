    #include <LiquidCrystal.h>

    /////////////////////////////////////////////////////////////////
   //             Arduino PIR sensor Tutorial           v1.00     //
  //       Get the latest version of the code here:              //
 //      http://educ8s.tv/arduino-pir-sensor-tutorial           //
/////////////////////////////////////////////////////////////////


#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7; // pins for the lcd from left to right
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // writting the pins to lcd

int ledPin = 13;
int pirPin = 52;
int val = 0;

void setup() 
{
  pinMode (ledPin,OUTPUT);
  pinMode (pirPin, INPUT);
  Serial.begin(9600);        // initialize serial
  lcd.begin(16, 2);          // sets the lcd varible
}

void loop () 
{
  val = digitalRead(pirPin);
  digitalWrite(ledPin,val);

if (val == 1){

  digitalWrite(ledPin,LOW);
  lcd.setCursor(0, 0);
  Serial.println("Motion!");
  lcd.print("Motion!");
  delay(500);
}

else {

   lcd.setCursor(0, 0);
      Serial.println("Motion stopped!");
      lcd.print("Motion stopped!");
      delay(500);
}
lcd.clear();
}

