#include <Servo.h>

int servoPin = 7;
int ultraPin = 11;

Servo servoObj;

void setup()
{
  servoObj.attach(servoPin);
  pinMode(ultraPin, OUTPUT);
}

void loop()
{
  servoObj.write(0);
  delay(500);
  
  float distance = (0.034 * getPulseTime())/2;  //distance in centimeter
  
  if(distance >= 100) {
    servoObj.write(90);
  	delay(3000);
  } else {
    servoObj.write(0);
  	delay(500);
  }
}

float getPulseTime() {
  float time = 0.0;
  
  digitalWrite(ultraPin, LOW);
  delayMicroseconds(2);
  
  //triggering
  digitalWrite(ultraPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(ultraPin, LOW);
  
  //receiving
  pinMode(ultraPin, INPUT);
  time = pulseIn(ultraPin, HIGH);
  
  return time;
}

