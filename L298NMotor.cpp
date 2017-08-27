/*
  L298NMotor.cpp - Library to control a DC Motor using an L298N driver Board.

  ( http://www.ebay.it/itm/Modulo-L298N-Dual-H-Bridge-DC-Stepper-Motor-Controller-Modulo-per-Arduino-/222406385028 )

  Le istruzioni sulla scheda sono state prese dalle pagine di Andrea Lombardo ( http://www.lombardoandrea.com/l298n-pilotare-un-motore-dc-con-arduino/ )

  Created by Marco Bevacqua, February 10, 2017.
  Released into the public domain.
*/

#include "Arduino.h"
#include "L298NMotor.h"

L298NMotor::L298NMotor(int IN1_pin, int IN2_pin, int Enable_pin)
{
  pinMode(IN1_pin, OUTPUT);
  pinMode(IN2_pin, OUTPUT);
  pinMode(Enable_pin, OUTPUT);
  _IN1_pin = IN1_pin;
  _IN2_pin = IN2_pin;
  _Enable_pin = Enable_pin;
}

/*
 Definisco il senso di marcia del motore
 
 _IN1 | _IN2 | Risultato
------|------|----------------------
 LOW  | LOW  | fermo
 LOW  | HIGH | Movimento in un senso
 HIGH | LOW  | Movimento senso opposto
 HIGH | HIGH | Fermo

Il senso di marcia dipende dall'ordine in cui sono collegati i due fili di alimentazione del motore, si può modificare
invertendo i fili o invertendo quale pin settare a LOW e quale a High nelle funzioni 

*/

void L298NMotor::forward(int speed)
{
  digitalWrite(_IN1_pin, HIGH);
  digitalWrite(_IN2_pin, LOW);
  setspeed(speed);
}

void L298NMotor::backward(int speed)
{
  digitalWrite(_IN1_pin, LOW);
  digitalWrite(_IN2_pin, HIGH);
  setspeed(speed);
}

void L298NMotor::stop_it()
{
  digitalWrite(_IN1_pin, LOW);
  digitalWrite(_IN2_pin, LOW);
  setspeed(0);
}

void L298NMotor::setspeed(int speed)
{
  _speed = speed;
  digitalWrite(_Enable_pin, _speed);
}

