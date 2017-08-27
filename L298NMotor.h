/*
  L298NMotor.h - Library to control a DC Motor using an L298N driver Board.

  ( http://www.ebay.it/itm/Modulo-L298N-Dual-H-Bridge-DC-Stepper-Motor-Controller-Modulo-per-Arduino-/222406385028 )

  Le istruzioni sulla scheda sono state prese dalle pagine di Andrea Lombardo ( http://www.lombardoandrea.com/l298n-pilotare-un-motore-dc-con-arduino/ )

  Created by Marco Bevacqua, February 10, 2017.
  Released into the public domain.
*/

#ifndef L298NMotor_h
#define L298NMotor_h

#include "Arduino.h"

class L298NMotor
{
  public:
   L298NMotor(int IN1_pin, int IN2_pin, int Enable_pin);
    void forward(int speed);
    void backward(int speed);
    void stop_it();
    void setspeed(int speed); // Set the Current motor speed 
  private:
    int _IN1_pin;  
    int _IN2_pin;
    int _Enable_pin;
    int _speed;      // Current speed setting
};

#endif
