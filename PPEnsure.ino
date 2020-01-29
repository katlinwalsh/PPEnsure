/* 
PPEnsure
Katlin Walsh 
DIGF 3010 | Advanced Wearable Electronics
OCAD University 
Created on January 29, 2020 

Based on: 
Hello_Speaker, Adafruit_CircuitPlayground Example, https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/Hello_CircuitPlayground/Hello_Speaker/Hello_Speaker.ino 
Hello_NeoPixels, Adafruit_CircuitPlayground Example, https://github.com/adafruit/Adafruit_CircuitPlayground/blob/master/examples/Hello_CircuitPlayground/Hello_NeoPixels/Hello_NeoPixels.ino
Hello_Analog, Carter Nelson, https://learn.adafruit.com/circuit-playground-analog-input/hello-analog
*/

#include <Adafruit_CircuitPlayground.h> //bring in Playground Library

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP); //Pin 3
}

void loop()
{
  int val= analogRead(3);
  Serial.println(val);
  bool pressed = false;
  if(val > 70) //edit this number for sensitivity changes!
  {
      Serial.println("Pressed"); //double check that the readings are working
      pressed = true;
  }
  
  if(!pressed)
  {
    CircuitPlayground.playTone(81, 1000, false); //plays E2 for 1 S with no delay

    for (int num = 0; num < 10; num++) 
    {
      CircuitPlayground.setPixelColor(num, 255, 0, 0); //all pins are red
    }

   CircuitPlayground.playTone(55, 1750, false); //Plays A1 for 1.75s with no delay

    for (int even = 0; even < 10; even+=2) 
    {
      CircuitPlayground.setPixelColor(even, 255, 0, 0); //Pins with even numbers are red
    }
    

    for (int odd = 1; odd < 10; odd+=2) 
    {
      CircuitPlayground.setPixelColor(odd, 255, 69, 0); //Pins with odd numbers are orange
    }
    

    delay(1500); //Delay for 1.5s
  }
  else 
  {
      for (int i = 0; i < 10; i++) 
      {
        CircuitPlayground.setPixelColor(i, 0, 102, 102); //all pins are teal
      }

      delay(100); //Don't delete this!
  }
}
