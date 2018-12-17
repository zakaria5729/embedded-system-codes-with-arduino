int trig = 5;
int eco = 6;

void setup()
{
  pinMode(trig, OUTPUT);
  pinMode(eco, INPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  
  //triggering
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  
  //receiving
  digitalWrite(eco, HIGH);
  
  float time = pulseIn(eco, HIGH);
  float distance = (time * 0.034)/2; //distance in centimeter
  
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(200);
    
}