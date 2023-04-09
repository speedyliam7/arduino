#include <LiquidCrystal.h>



int buzz = 2;
//liquid crystal

const int rs = 8, en = 9, d4 = 5, d5 = 4, d6 = 3, d7 = 7;  // pins for the lcd from left to right
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);                 // writting the pins to lcd

//motion
int pirPin = 52;
int val = 0;
int wait = 500;
//ultrasonic
#include <NewPing.h>

#define TRIGGER_PIN 11
#define ECHO_PIN 12
#define MAX_DISTANCE 200
int distance1 = 0;
int distance2 = 0;
int speed = 0;
long duration;
int distance = 0;
float ultrasonicRead();
int lastspeed = 0;
int lastdist = 0;
char strLine1[16];
char strLine2[16];
// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


void setup() {

  pinMode(pirPin, INPUT);
  Serial.begin(9600);  // initialize serial
  lcd.begin(16, 2);    // sets the lcd varible
  pinMode(buzz, OUTPUT);
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  //distance
  distance1 = ultrasonicRead();
  delay(1000);
  distance2 = ultrasonicRead();
  speed = abs(distance2 - distance1) / 1.0;
  val = digitalRead(pirPin);
  //delay(250);
  unsigned int distance = sonar.ping_cm();

  if (val == 1) {
    lcd.clear();

    lcd.setCursor(0, 0);
    lcd.print("Motion!, ");
    lcd.print(distance);
    lcd.print("cm");
    if (distance <= 200) {

      lcd.setCursor(0, 1);
      lcd.println("speed:");
      lcd.print(speed);
      lcd.println("cm/s");
      Serial.print("speed in cm/s: ");
      Serial.println(speed);
    }
    delay(2000);
    //lcd.clear();
  } else {
    int lastspeed = speed;
    int lastdist = distance;




    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print("no Motion");
    lcd.setCursor(0,1);
    lcd.print("last dist: ");
      lcd.print(lastdist);
      lcd.print("cm");
      lcd.setCursor(0,1);
      
      delay(wait);
  lcd.print(lastspeed);
  lcd.println("cm/s");
  }
  delay(wait);
}


float ultrasonicRead() {


  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  duration = pulseIn(ECHO_PIN, HIGH);
  distance = duration * 0.034 / 2;
  return distance;
}