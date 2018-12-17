int ledRed = 3;
int ledGreen = 7;
int buzzer = 11;
int LM35 = 2; //A2

void setup()
{
  pinMode(LM35, INPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(LM35);
  int temp = value * 0.48;
  
  Serial.println(temp);
  
  if(temp < 20) {
    digitalWrite(ledGreen, HIGH);
    digitalWrite(ledRed, LOW);
    noTone(buzzer);
  } else {
    digitalWrite(ledRed, HIGH);
    digitalWrite(ledGreen, LOW);
    tone(buzzer, 400);
  }
}