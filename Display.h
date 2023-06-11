/*
*
*   Code made by EccoEdd
*   for more information contact to
*   coriaedd@gmail.com   
*
*   06/04/2023
*
*/

#include <LiquidCrystal.h>
#include "Timer.h"

class Display {
public:
  Display(int rs, int enable, int d4, int d5, int d6, int d7)
    : lcd(rs, enable, d4, d5, d6, d7) {
        lcd.begin(16, 2);
    }

  void timerDisplay() {
    lcd.setCursor(0, 1);
    timer.update();

    unsigned int hours = timer.getHours();
    unsigned int minutes = timer.getMinutes();
    unsigned int seconds = timer.getSeconds();

    lcd.print("  ");
    lcd.print(hours);
    lcd.print(":");

    if (minutes % 60 < 10) {
      lcd.print("0");
    }
    lcd.print(minutes % 60);
    lcd.print(":");

    if (seconds % 60 < 10) {
      lcd.print("0");
    }
    lcd.print(seconds % 60);
    lcd.print(" Timer");
  }

  void test(){
    lcd.setCursor(0, 0);
    lcd.print("  Hello World!");
  }

  void personalizedMessage(String message){
    lcd.setCursor(0, 0);
    lcd.print(message);
  }
  
private:
  LiquidCrystal lcd;
  Timer timer;
};
