/*PROGRAMA SORTEO PILULA DE ARDUINO 2017*/

/*Declaracion de variables*/
long randNumber;  //Almacena el numero aleatorio que nos devuelve
int indice;
int counter;
int i,g;

/*Array de cadenas con todos los participantes en el sorteo*/
String participantes[86]={

"107575",
"104980",
"104784",
"103040",
"103055",
"106397",
"103216",
"108895",
"106394",
"104858",
"107314",
"106363",
"102913",
"106286",
"108828",
"107539",
"108264",
"107543",
"106218",
"106326",
"104964",
"108087",
"106355",
"108909",
"104801",
"108968",
"106243",
"104115",
"106283",
"108922",
"106330",
"104057",
"104133",
"108661",
"104811",
"103158",
"106287",
"105018",
"102965",
"104857",
"106796",
"103008",
"104945",
"106257",
"107587",
"106362",
"107563",
"106819",
"107365",
"105015",
"106289",
"108944",
"108902",
"104141",
"106273",
"106313",
"106371",
"107582",
"107378",
"106807",
"106324",
"107705",
"108462",
"106258",
"106322",
"104997",
"105057",
"108628",
"104826",
"108949",
"109041",
"105122",
"104172",
"104177",
"106971",
"106365",
"104836",
"105110",
"108085",
"106370",
"106279",
"106808",
"104842",
"108008",
"104171"
};

long Ganadores[12];
bool flagRepe;

void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  

  i=0;
  while(i<12)
  {
    randNumber = random(0,85);

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


