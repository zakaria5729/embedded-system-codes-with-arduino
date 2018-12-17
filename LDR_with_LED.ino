int LDR = 0; //A0
int LED = 3;

void setup()
{
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int value = analogRead(LDR);
  Serial.println(value);
  
  if(value < 200) { //here we consider that <500 means darkness
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}