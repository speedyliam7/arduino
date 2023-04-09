

#include <LiquidCrystal.h>


const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 7; // pins for the lcd from left to right
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // writting the pins to lcd
 
               // the pin that the LED is atteched to
int pir = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
  pinMode(pir, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  lcd.begin(16, 2);          // sets the lcd varibles
  delay(6000)
}

void loop(){
  val = digitalRead(pir);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
    delay(1000);                // delay 100 milliseconds 
    
    if (state == LOW) {
      lcd.setCursor(0, 1);
      Serial.println("Motion detected!");
      lcd.print(millis() / 1000); 
      state = HIGH;       // update variable state to HIGH

    }
  } 
  else {
      digitalWrite(led, LOW); // turn LED OFF
      delay(1000);             // delay 200 milliseconds 
      
      if (state == HIGH){
        lcd.setCursor(0, 1);
        Serial.println("Motion   stopped!");
        lcd.print(millis() / 1000); 
        state = LOW;       // update variable state to LOW
    }
  }
}