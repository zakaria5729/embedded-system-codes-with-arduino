int PIR = 5;
int LED = 13;

int pirState = HIGH; //set default value

void setup()
{
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);
}

void loop()
{
  int value = digitalRead(PIR);
  
  if(value == HIGH) {
    if(pirState == HIGH) {
      	Serial.println("Moton start..");
      	digitalWrite(LED, HIGH);
      
      	pirState = LOW;
    }
  } else {
    if(pirState == LOW) {
     	Serial.println("Moton end");
      	digitalWrite(LED, LOW);
    }
    
    pirState = HIGH; //set default value again
  }
}