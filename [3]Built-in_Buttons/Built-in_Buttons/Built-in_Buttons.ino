#define KNOPLINKS 0       //Defineer pin 0 als KNOPLINKS
#define KNOPRECHTS 35

void setup() {    //Loopt 1x bij het opstarten van de microcontroller
  pinMode(KNOPLINKS,INPUT_PULLUP);    //Defineer de pin van de linkerknop als input 
  pinMode(KNOPRECHTS,INPUT_PULLUP);    //Defineer de pin van de rechterknop als input

  Serial.begin(115200);               //Bereid de communicatie naar de computer voor
}


void loop() {   //Blijft lopen zolang de microcontroller voeding heeft (5V of 3.3V)

  if(digitalRead(KNOPLINKS)==0){    //Test of de knop is ingedrukt (Actief laag --> bij 0 is de knop ingedrukt)
    Serial.println("Linkerknop ingedrukt.");    //Print een tekstje naar de Serial Monitor (Tools --> Serial Monitor)
  }
  
  if(digitalRead(KNOPRECHTS)==0){
    Serial.println("Rechterknop ingedrukt.");
  }
  
  delay(100);   //Wacht 100 milliseconden (anders loopt de code veel te snel!)
}
