
// Configureer het LED pin nummer
const int LedPin =  12;    // the number of the LED pin


void setup() {
  Serial.begin(115200);  
  // initialize the LED pin as an output
  pinMode(LedPin, OUTPUT);
}

void loop() {
    digitalWrite(LedPin, HIGH);
    delay(500);
    digitalWrite(LedPin, LOW);
    delay(500);
}
