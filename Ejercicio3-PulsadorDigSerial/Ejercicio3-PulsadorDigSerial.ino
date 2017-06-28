
int pulsador = 4;
int led= 13;

void setup()
{
  pinMode(pulsador, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (digitalRead(pulsador) == HIGH)
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
  Serial.println(digitalRead(pulsador));
}


