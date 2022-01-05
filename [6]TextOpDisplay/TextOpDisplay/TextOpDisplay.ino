/*  
 Deze sketch zal text weergeven op het TFT display van de TTGO T-Display in verschillende kleuren/groottes
  Opgelet: Denk er aan om "User_Setup.h" aan te passen!
*/

#include <TFT_eSPI.h> // Library gebruikt om de displaydriver mee aan te sturen
//#include <SPI.h>      // Library om te communiceren met de display driver

#define TFT_GREY 0x5AEB   //Voorbeeld: Definieer eigen kleur.
//Vooraf gedefineerde kleuren:
  //TFT_BLACK, TFT_NAVY, TFT_DARKGREEN, TFT_DARKCYAN, TFT_MAROON, TFT_PURPLE, TFT_OLIVE, TFT_LIGHTGREY, 
  //TFT_DARKGREY, TFT_BLUE, TFT_GREEN, TFT_CYAN, TFT_RED, TFT_MAGENTA, TFT_YELLOW, TFT_WHITE, 
  //TFT_ORANGE, TFT_GREENYELLOW, TFT_PINK, TFT_BROWN, TFT_GOLD, TFT_SILVER, TFT_SKYBLUE, TFT_VIOLET

TFT_eSPI tft = TFT_eSPI();  //Maak een object aan va de klasse TFT_eSPI

void setup(void) {
  tft.init();           //Start de communicatie met het display
  tft.setRotation(1);   //Roteert de weergave op het display. Mogelijke waarden: 0-3.
}

void loop() {
  // Maak het volledige scherm blauw
  tft.fillScreen(TFT_NAVY);
  
  // Zet de cursor (waar de text moet komen) in de linker-bovenhoek(0,0) en kies letertype '2'
  // Door gebruik te maken van de printline (println) functie: "tft.println()" wordt er na het printen naar de volgende regel gesprongen.
  //  gebruik "tft.print()" om na het printen niet naar de volgende regel te springen.
  tft.setCursor(0, 0, 2);
  
  //Maak de tekstkleur Wit, op een zwarte achtergrond, tekstgrootte '1'
  tft.setTextColor(TFT_WHITE,TFT_BLACK);  
  tft.setTextSize(1);
  // Door gerbuik te maken van het print-commando kan je tekst op het scherm zetten.
  tft.println("Schermtest!");
  
  // Maak de tekst grijs, met een  letterype '7'
  tft.setTextColor(TFT_GREY); 
  tft.setTextFont(7);
  float Getal = 1234.56;
  tft.println(Getal);   //Print een getal
  
  // Maak de tekstkleur groen op een zwarte achtergrond, maak eht lettertype '4'
  tft.setTextColor(TFT_GREEN,TFT_BLACK);
  tft.setTextFont(4);
  tft.println("Print hier");
  tft.println("Volgende regel.");

  // Tekst formatteer-functies: 
  tft.setTextColor(TFT_BLUE);    
  tft.setTextFont(4);
  tft.print("Kommaget = "); tft.println(Getal);               // Print een kommagetal
  tft.print("Binair = "); tft.println((int)Getal, BIN);       // Print het gehele deel als binair
  tft.print("Hexadecimaal = "); tft.println((int)Getal, HEX); // Print het gehele deel Hexadecimal
  delay(10000);
}
