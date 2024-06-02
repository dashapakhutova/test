#ifdef _CODE_HELLO
#else
#define _CODE_HELLO

#include "leds.c"

//Мигание светодиодами на старте
void hello ( void ) {
  void f ( struct Color *c ) {
    userLed.color = c;
  }
  f(&ColorRed); delay(10); f(&ColorBlack); delay(50);
  f(&ColorRed); delay(10); f(&ColorBlack); delay(50);
  f(&ColorRed); delay(10); f(&ColorBlack); delay(50);
  f(&ColorGreen); delay(10); f(&ColorBlack); delay(50);
  f(&ColorGreen); delay(10); f(&ColorBlack); delay(50);
  f(&ColorGreen); delay(10); f(&ColorBlack); delay(50);
  f(&ColorBlue); delay(10); f(&ColorBlack); delay(50);
  f(&ColorBlue); delay(10); f(&ColorBlack); delay(50);
  f(&ColorBlue); delay(10); f(&ColorBlack);
  delay(300);
}
#endif
