#include "MicroBit.h"

MicroBit uBit;

int main()
{
  uBit.init();

  while (true) {
    uBit.display.image.setPixelValue(2, 2, 9);
    uBit.sleep(1000); // sleep for one second
    uBit.display.image.setPixelValue(2, 2, 0);
    uBit.sleep(1000);
  }
  
}
