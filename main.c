#include <stm32g431xx.h>
#include "lib/pins.c"
#include "lib/bases.c"
#include "lib/helpers.c"
#include "lib/macros.c"
#include "system.c"
#include "colors.c"
#include "matrix.c"
#include "buttons.c"
#include "nose.c"
#include "roar.c"
#include "random.c"
#include "images.c"

uint8_t foo = 0;
uint8_t dir = 0;
uint8_t pause = 0;
uint32_t insanity = 0;
uint16_t digit = 1;
uint8_t digitSW = false;

#define D delay(10)

void checkLight(uint16_t light, int counter) {
  delay(1);
  if (counter >= 2) {
    if (light == 0) {
      eyeL.color = &ColorPurple;
      eyeR.color = &ColorPurple;
    }
    if (light > 0) {
      eyeL.color = &ColorRed;
      eyeR.color = &ColorRed;
    }
    if (light > 100) {
      eyeL.color = &ColorYellow;
      eyeR.color = &ColorYellow;
    }
    if (light > 1000) {
      eyeL.color = &ColorGreen;
      eyeR.color = &ColorGreen;
    }
  roar = false;
  if ( dir == 1 ) foo = 0;
  foo = 0;
  insanity = 0;
  imageSpiral(senseNose());
  }
}

int test_increment(int counter) {
  counter++;
  delay(1);
  return counter;
}

int test_decrement(int counter) {
  counter = 0;
  delay(4);
  return counter;
}

void main ( void ) {
  initEyes();
  //hello();
  matrix[2][2] -> value = 100;
  initPin_InputPU(GPIOA,0);
  initPin_InputPU(GPIOB,13);
  initADC_Common();
  initADC1();
  initRoar();
  int test = 0;
  
  //delay(500); matrix[1][1] -> value = 10;
  //delay(500); matrix[3][3] -> value = 200;
  //delay(500); matrix[4][0] -> value = 1;
  //delay(3000);

  while (1) {
    /*
    eyeL.color = &ColorRed; delay(500);
    eyeL.color = &ColorGreen; delay(500);
    eyeL.color = &ColorBlue; delay(500);
    eyeL.color = &ColorOrange; delay(500);
    eyeL.color = &ColorYellow; delay(500);
    eyeL.color = &ColorLime; delay(500);
    eyeL.color = &ColorPink; delay(500);
    eyeL.color = &ColorPurple; delay(500);
    eyeL.color = &ColorCyan; delay(500);
    eyeL.color = &ColorWhite; delay(500);
    eyeL.color = &ColorPerfectWhite; delay(500);
    */

    switch ( checkButtons()) {
      case 0b00: //не нажато
        eyeL.color = &ColorOrange;
        eyeR.color = &ColorYellow;
        roar = false;
        pause = 0;
        insanity = 0;
        if (digitSW) {
          digitSW = false;
          digit++;
        }
        break;
      case 0b01: //левая
        eyeL.color = &ColorCyan;
        eyeR.color = &ColorGreen;
        roar = false;
        if ( dir == 0 ) foo = 0;
        insanity = 0;
        foo = 0;
        pause = 0;
        test = test_decrement(test);
        imageDigit(digit);
        digitSW=true;
        continue;
        break;
      case 0b10: //правая
        eyeL.color = &ColorWhite;
        eyeR.color = &ColorBlue;
        insanity++;
        if ( insanity > 250 ) {
          roar = true;
          randomMatrix();
          delay(1);
        }
        else {
          imageCross(insanity); delay(3); continue;
        }
        foo = 0;
        test = test_decrement(test);
        break;
      default:
        break;
        // roar = false;
        // if ( dir == 1 ) foo = 0;
        // // dir = 0;
        // foo = 0;
        // pause = 0;
        // insanity = 0;
        // test = test_decrement(test);
        // imageArrowR();
        // continue;
        // break;
      case 0b11: //обе
        eyeL.color = &ColorRed;
        eyeR.color = &ColorRed;
        roar = false;
        if ( dir == 1 ) foo = 0;
        // dir = 0;
        foo = 0;
        // pause = 0;
        insanity = 0;
        test = test_increment(test);
        imageArrowR();
        continue;
        break;
        // insanity++;
        // if ( insanity > 250 ) {
        //   roar = true;
        //   randomMatrix();
        //   delay(1);
        // }
        // else {
        //   imageCross(insanity); delay(3); continue;
        // }
        // foo = 0;
        // test = test_increment(test);

        // roar = true;
        // randomMatrix();
        // foo = 0;
        // test = test_increment(test);
      //   break;
      // default:
      //   break; 
    }

    checkLight(senseNose(), test);
    
    delay(5);
    if ( roar ) {
      delay(40);
      continue;
    }

    for ( int i=0; i<5; i++ )
      for ( int j=0; j<5; j++ ) {
        if (dir) {
          matrix[i][j] -> value = (foo + 10*(i+j));
        }
        else {
          matrix[i][j] -> value = (foo + 10*((4-i)+j));
        }
      }
    if ( pause == 0 ) foo++;
  }
}