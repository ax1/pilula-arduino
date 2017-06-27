int pulsador = 2;
int rele= 13;

void setup()
{
  pinMode(pulsador, INPUT);
  pinMode(rele, OUTPUT);
}

void loop()
{
  if (digitalRead(pulsador) == HIGH)
  {
    digitalWrite(rele, HIGH);
  }
  else
  {
    digitalWrite(rele, LOW);
  }
}

