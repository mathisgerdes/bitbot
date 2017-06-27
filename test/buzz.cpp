#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "bitbot/bitbot.h"

// needed for fiber
MicroBitMessageBus bus;
BitBot bitbot;

int main()
{
  scheduler_init(bus);

  bitbot.buzz(1000);
  fiber_sleep(1000);
  bitbot.buzz(500);

  release_fiber();
}
