/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/
#include "Plotter.h"

Plotter p;
double VP3, VP5, V3BD;

// the setup routine runs once when you press reset:
void setup() {
   p.Begin();
   // Add 3 variable time graph
    p.AddTimeGraph( "3 variable time graph", 1500, "3.3 V P Supply", VP3, "5V P Supply", VP5, "Nexys 3.3 BD Supply", V3BD);
 
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue0 = analogRead(A0);
  // read the input on analog pin 1:  
  int sensorValue1 = analogRead(A1);

  // read the input on analog pin 1:  
  int sensorValue2 = analogRead(A2);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  VP3 = sensorValue0 * (5.0 / 1023.0);   //3V3 Power Supply Voltage
  VP5 = sensorValue1 * (5.0 / 1023.0);   //5V Power Supply Voltage
  V3BD = sensorValue2 * (5.0 / 1023.0);   //3.3V - NexysA7 Supply Voltage
//From power supply
  Serial.println("3.3V:");      //A0
  Serial.println(VP3);
  Serial.println("5V:");      //A1
  Serial.println(VP5);
  //From Board
  Serial.println("3V3 BD:");
  Serial.println(V3BD);    //A2

 //Plot the values
 p.Plot();
}
