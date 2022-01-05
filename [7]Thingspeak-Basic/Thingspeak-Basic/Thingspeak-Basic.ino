/*
 * Let op, om deze code te gebruiken heb je nog wat extra dingen nodig:
 * 1. Via de Library manager (Ctrl + Shift + i) Thingspeak by Mathworks toevoegen
 * 2. Account aanmaken op "thingspeak.com" en een kanaal aanmaken (Noem het Signaalsterkte)
 * 3. Kopieer je Kanaalnummer en Write API key, en plak deze in de schets hieronder op de juiste plek
 * 4. Vul je netwerk SSID en Wachtwoord in op de juiste plek
 * 5. Na het schrijven van de code naar je arduino, open je thinkspeak kanaal en zie je data binnenkomen
 
  Geleend van Rui Santos
  Hij beseerde zicj op het WriteSingleField voorbeeld uit de ThingSpeak Library (Mathworks)
  Complete project details at https://RandomNerdTutorials.com/esp32-thingspeak-publish-arduino/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

#include <WiFi.h>
#include "ThingSpeak.h"


const char* ssid = "VERVANGEN_MET_JE_EIGEN_SSID";   // Jouw netwerk SSID, laat de aanhalingstekens staan!
const char* password = "VERVANGEN_MET_JE_EIGEN_PASSWORD";   // Jouw netwerk password, laat de aanhalingstekens staan!

WiFiClient  client;

unsigned long myChannelNumber = 123456;        //Jouw Thingspeak kanaalnummer, geen aanhalingstekens nodig!
const char * myWriteAPIKey = "XXXXXXXXXXXXXXXX";  //Jouw API write key, laat de aanhalingstekens staan!

// Timer variables
unsigned long lastTime = 0;
unsigned long timerDelay = 30000;


void setup() {
  Serial.begin(115200);  //Start seriële communicatie
  
  WiFi.mode(WIFI_STA);   //Stel de WiFi modus in als een normale client (Station mode)
    
  ThingSpeak.begin(client);  // Start ThingSpeak 
}


void loop() {
  if ((millis() - lastTime) > timerDelay) {   //In plaat van delay() te gebruiken
    
    // Connect or reconnect to WiFi
    if(WiFi.status() != WL_CONNECTED){    //Test of WiFi verbonden is
      
      Serial.print("Verbinden met WiFi");
      WiFi.begin(ssid, password);       //Verbinden met Wifi
      
      while(WiFi.status() != WL_CONNECTED){   //Zolang geen verbinding, print een '.'
        Serial.print('.');
        delay(500);     
      } 
      Serial.println("\nVerbonden!");
    }

    long WifiSterkte = WiFi.RSSI();   //Meet de sterkte van het wifi signaal
    int ErrorCode = ThingSpeak.writeField(myChannelNumber, 1, WifiSterkte, myWriteAPIKey);
    if(ErrorCode == 200){
      Serial.println("Channel update geslaagd.");   //Schrijven geslaagd
    }
    else{
      Serial.println("Probleem met updaten van Thingspeak. HTTP error code: " + String(ErrorCode));   //Schrijven niet geslaagd
    }
    lastTime = millis();    //Update de tijd waarop deze meting uitgevoerd is naar de huidige tijd.
  }
}
