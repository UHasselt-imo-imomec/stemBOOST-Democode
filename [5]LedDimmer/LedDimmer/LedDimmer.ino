// Configureer het LED pin nummer
const int LedPin = 25;

// Configureer de PWM eigenschappen
const int freq = 5000;    //Frequentie: aantal keer per seconde data de LED aan/uit zal gaan
const int ledChannel = 0; //intern kanaal 
const int resolution = 8; //Resolutie: aantal stapjes waarmee de helderheid kan toenemen (2^8 == 256)

//Wordt 1x uitgevoerd 
void setup(){
  Serial.begin(115200);
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(LedPin, ledChannel);
  Serial.println("LED dimmer start.");
}

//Wordt continue uitgevoerd 
void loop(){
  // Verhoog de helderheid
  Serial.print("\nMeer helder: ");
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   //Doorloop de for-lus, waarbij dutyCycle telkens met 1 verhoogd wordt
    ledcWrite(ledChannel, dutyCycle);   //Schrijf de Duty-cycle waarde naar ledChannel
    Serial.print('+');                  //Print tekst naar de serial monitor
    delay(15);                          //Wacht 15 msec, anders wordt de helderheid te snel opgehoogd.
  }

  // Verlaag de helderheid
  Serial.print("\nMinder helder: ");
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){   //Doorloop de for-lus, waarbij dutyCycle telkens met 1 verlaagd wordt
    ledcWrite(ledChannel, dutyCycle);   //Schrijf de Duty-cycle waarde naar ledChannel
    Serial.print('-');                  //Print tekst naar de serial monitor   
    delay(15);                          //Wacht 15 msec, anders wordt de helderheid te snel verlaagd.
  }
}
