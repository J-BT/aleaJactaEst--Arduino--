int nbAlea;
int led;
int pinBouton = 10;
int pinLed[5]={2,3,4,5,6};
boolean etatLed = HIGH; 
boolean ledEteintes[6][5]={
  1,1,1,1,1,      // random = 0
  1,0,1,1,1,      // random = 1
  1,1,0,0,1,      // random = 2
  1,0,0,0,1,      // random = 3
  0,1,0,0,0,      // random = 4
  0,0,0,0,0       // random = 5
};
int intervalleDes = 100;

//#TESTS ou REAL#
boolean TEST = false;
boolean REAL = true;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0)); //Initialisation seq aléatoire
  pinMode(pinBouton, INPUT_PULLUP); //On prepare l'interrupteur 
  for (led = 0; led < 5 ; led++){
    pinMode(pinLed[led], OUTPUT); //On prepare les pin des LED
    digitalWrite(pinLed[led], HIGH); // On les eteint toutes LED
  }
}// void setup

void loop() {
  boolean bouton = digitalRead(pinBouton); // On = 0 , Off = 1
  if (bouton == 0){   //Si l'on appuie sur le bouton
    while (intervalleDes < 1600){
      nbAlea=random(6); // créer nb aléatoire
      
      Serial.print("nombre aléatoire = ");
      Serial.print(nbAlea);
      Serial.print(",  delai =");
      Serial.println(intervalleDes);
      
      if (TEST){
        if (etatLed == HIGH){
          etatLed = LOW;
        }
        else{
          etatLed = HIGH;
        }
        for (led = 0; led < 5 ; led++){
          digitalWrite(pinLed[led], etatLed); 
        }
      }//if TEST
    
      if (REAL){
          for (led = 0; led < 5 ; led++){
            digitalWrite(pinLed[led], ledEteintes[nbAlea][led]); 
          } 
      }//if REAL
     delay(intervalleDes);
     intervalleDes += 100; 
    }// while  
  }// if bouton == 0
}// loop
