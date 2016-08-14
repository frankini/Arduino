/*
 * Simple timer using Adafruit 7-segment LED backback
 * 
 * Steven Frankini - 2016
*/

#include <Wire.h>

#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  matrix.begin(0x70);
}

void loop() {
  
  bool drawdots = false;
  
  for (int m = 0; m < 99; m++) {
    //print minuets
    matrix.writeDigitNum(0, (m / 10), drawdots);
    matrix.writeDigitNum(1, (m % 10), drawdots);
    
    for (int s = 0; s < 59; s++) {
      // print seconds
      matrix.writeDigitNum(3, (s / 10), drawdots);
      matrix.writeDigitNum(4, (s % 10), drawdots);
      matrix.writeDisplay();
      delay(40);
    }
  }
}
