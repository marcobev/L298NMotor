/*
 * L298N_Test  Test della libreria L298NMotor per pilotare due motori DC con Arduino e la scheda L298N Dual H-Bridge
 * 
 * ( http://www.ebay.it/itm/Modulo-L298N-Dual-H-Bridge-DC-Stepper-Motor-Controller-Modulo-per-Arduino-/222406385028 )
 *  
 * Le istruzioni sulla scheda sono state prese dalle pagine di Andrea Lombardo ( http://www.lombardoandrea.com/l298n-pilotare-un-motore-dc-con-arduino/ )
 * 
 * Autore  : Marco Bevacqua
 * Web     : 
 * Post    : 
 * Git     : 
 */ 

#include <L298NMotor.h>

//definizione dei pin
//
// Motore 1
static int m1A = 8; //pin digitale per determinare gli stati logici da inviare al modulo
static int m1B = 7; //pin digitale per determinare gli stati logici da inviare al modulo
static int pinPotenza1 = 9; //pin tramite il quale inviare un segnale di tipo PWM tramite la funzione analgWrite()

// Motore 2
static int m2A = 13; //pin digitale per determinare gli stati logici da inviare al modulo
static int m2B = 12; //pin digitale per determinare gli stati logici da inviare al modulo
static int pinPotenza2 = 11; //pin tramite il quale inviare un segnale di tipo PWM tramite la funzione analgWrite()

//variabili usate per gestire e mostrare i valori di operaizone
int accelerazione;  
int potenza;  

// Istanzio gli oggetti per i motori
L298NMotor Motore1 = L298NMotor ( m1A, m1B, pinPotenza1 ) ;
L298NMotor Motore2 = L298NMotor ( m2A, m2B, pinPotenza2 ) ;
 
void setup() {
  //inizializzo la comunicazione seriale cosi da mostrare i valori nel Monitor Seriale
  Serial.begin(9600);

  //inizializzo variabili
  accelerazione = 0;
  potenza = 0;
}

void loop() {
  accelerazione = 30 ;  // Per ora uso un valore fisso
 
  /*
  Il range dei valori analogici e' da 0 a 1024 mentre il range dei valori PWM  e' da 0 a 255
  per mantenere questa proporzionalita' eseguo la mappatura dei valori
  */
  potenza = map(accelerazione, 0, 1024, 0, 255);

  //Invio i dati letti al Monitor seriale, cosi da poterli vedere a video
  Serial.print("Accelerazione = ");
  Serial.print(accelerazione);
  Serial.print(" - potenza = ");
  Serial.println(potenza);

  Serial.println("Motore1: Avanti - Motore2: Avanti");
  Motore1.forward(potenza);
  Motore2.forward(potenza);
  delay(1500);

  Serial.println("Motore1: Indietro - Motore2: Indietro");
  Motore1.backward(potenza);
  Motore2.backward(potenza);
  delay(1500);
  Serial.println("Motore1: Fermo - Motore2: Fermo");
  Motore1.stop_it();
  Motore2.stop_it();
  delay(1500);
  
  Serial.println("Motore1: Avanti - Motore2: Indietro");
  Motore1.forward(potenza);
  Motore2.backward(potenza);
  delay(1500);

  Serial.println("Motore1: Indietro - Motore2: Avanti");
  Motore1.backward(potenza);
  Motore2.forward(potenza);
  delay(1500);

  Serial.println("Motore1: Fermo - Motore2: Fermo");
  Motore1.stop_it();
  Motore2.stop_it();
  delay(1500);
}
