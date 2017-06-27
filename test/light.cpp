#include "MicroBitDisplay.h"
#include "bitbot/bitbot.h"

BitBot bitbot;
MicroBitDisplay display;

int main()
{
  int brightness {0};
  while (true) {
    brightness = bitbot.lightPercent() / 10;
    display.print(brightness);
    fiber_sleep(100);
  }

  release_fiber();
}
