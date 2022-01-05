// ESP32 Touch read: verbind een draadje met de TouchPin, hieronder gedefinieerd.
// Met touch read kan je een knop maken, zonder schakelaar.

const int TouchPin = 2;	//Pin waarop mee je een kabeltje verbind
int TouchValue = 0;	//Variabele om de "touch"waarde van de bovenstaande pin in op te slaan

void setup() {		//Wordt 1x uitgevoerd
  Serial.begin(115200);
  Serial.println("ESP32 Touch Test");
}

void loop() {		//Wordt telkens opnieuw doorlopen
  TouchValue = touchRead(TouchPin);
  Serial.println(TouchValue);
  delay(500);
}
