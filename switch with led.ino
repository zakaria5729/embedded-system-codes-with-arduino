int led = 13;
int pushButton = 7;
int state = 0;

void setup()
{
  pinMode(pushButton, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  state = digitalRead(pushButton);
  
  digitalWrite(led, state);
}