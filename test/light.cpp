#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "MicroBitDisplay.h"
#include "bitbot/bitbot.h"

MicroBitMessageBus bus;
MicroBitDisplay display;
BitBot bitbot;

int main()
{
  scheduler_init(bus);

  int brightness {0};
  while (true) {
    brightness = bitbot.lightPercent() / 10;
    display.print(brightness);
    fiber_sleep(100);
  }

  release_fiber();
}
