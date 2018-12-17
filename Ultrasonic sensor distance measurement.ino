int pin = 5;

void setup()
{
  pinMode(pin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //divided by 2 because of coming and going pluse time
  float distance = (0.034 * getPulseTime())/2; //distance in centimeter
  
  Serial.print(distance);
  Serial.println(" cm");
  
  delay(200);
}

float getPulseTime() {
  float time = 0.0;
  
  //triggering
  digitalWrite(pin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(pin, LOW);
  
  //receiving
  pinMode(pin, INPUT);
  time = pulseIn(pin, HIGH);
  
  return time;
}