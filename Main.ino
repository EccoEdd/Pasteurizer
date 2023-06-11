/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com   
*
*   06/04/2023
*
*/

#include "Display.h"
#include "Temperature.h"
#include "Led.h"
#include "Rele.h"

Display display(8, 9, 4, 5, 6, 7);
Temperature temperature(0);
Led led(13, 12, 11);
Rele re(2);

double temp;

void setup(){
  Serial.begin(9600);
}

void loop(){
  temp = temperature.getTemperature();
  display.personalizedMessage("  temp:" + String(temp) + " C");
  display.timerDisplay();
  led.control(temp);
  re.tempController(temp);
  delay(1000);
}