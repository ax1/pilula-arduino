/*PROGRAMA SORTEO PILULA DE ARDUINO 2017*/

/*Declaracion de variable*/
long randNumber;
int indice;
int counter;
int i,g;

/*Array de cadenas con todos los participantes en el sorteo*/
String participantes[100]={
  "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329",
    "106320",
  "106321",
  "106322",
  "106323",
  "106324",
  "106325",
  "106326",
  "106327",
  "106328",
  "106329"
};

long Ganadores[12];
bool flagRepe;

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  

  i=0;
  while(i<12)
  {
    randNumber = random(0,100);

    flagRepe=false;
    for(g=0;g<=i;g++)
    {
      if (Ganadores[g]==randNumber)
      {
        flagRepe=true;
      }
    }
    
    if (flagRepe==false)
    {
        Ganadores[i]=randNumber;
        i++;
        Serial.print("Ganador numero: ");
        Serial.println(i);
        Serial.print("Posicion: ");
        Serial.println(randNumber);
        Serial.print("ID: ");
        Serial.println(participantes[randNumber]);
        delay(50);
    }
  }
}

void loop(){
  



}

