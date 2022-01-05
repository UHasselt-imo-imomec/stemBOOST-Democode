//Voorbeeldcode voor de PIR sensor met ESP32, aansluitingen zoals in de presentatie


#define PIRPIN 26   //Definieer de pin waarop de PIR sensor is aangesloten

void setup() {    //Wordt 1x uitgevoerd (bij opstart van de microcontroller
  pinMode(PIRPIN, INPUT);   //Configureer de pin waar de PIR sensor op aangesloten is als ingang
  Serial.begin(115200);     //Start communicatie over de seriele poort (op 115200 bits per seconde, deze waarde moet ook onderaan in de serial monitor staan).
}

void loop() {   //Wordt uigevoed na de setup(), en blijft uitgevoerd worden
  int PIRWaarde = digitalRead(PIRPIN);    //Lees de toestand van de PIR pin in, en schrijf deze waarde naar de variabele PIRWaarde

  if (PIRWaarde == HIGH) {                //Als de PIR sensor een actief is, dan zal een bericht naar de Serial Monitor geschreven worden.
    Serial.println("Beweging gezien!");
    delay(100);        //Even wachten, anders wordt er veel te vaak text geprint
  }

  delay(10);        //Even wachten, dit staat de microcontroller toe om andere taken af te werken.
}
