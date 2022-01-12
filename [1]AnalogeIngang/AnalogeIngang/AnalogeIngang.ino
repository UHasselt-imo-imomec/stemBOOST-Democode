
// Analoog signaal of potentiometer verbinden met een analoge pin. (bv: 36, 39, 32, 33)
// Let op: Analoog singaal tussen 0 en 3.3V!

const int AnalogInPin = 36;

// Variabele bevat de waarde van de analoge ingang. Waarde van 0 tem 4095 (12bit = 2^12)
int AnalogValue = 0;

//Voer 1x uit, bij opstart
void setup() {
  Serial.begin(115200);		//Start de communicatie naar de Serial Monitor
  Serial.println("Start analoge datameting.");
}

//Blij eindeloos uitvoeren
void loop() {
  AnalogValue = analogRead(AnalogInPin); 	//Lees de analoge waarde, en sla op in "AnalogValue"
  Serial.println(AnalogValue);		//Print deze waarde naar de terminal
  delay(500);	//==500 msec --> beperkt de print tot 2 punten per seconde
}
