#include "bitbot/bitbot.h"

BitBot bitbot;

// needed for fiber
MicroBitMessageBus bus;

int main()
{
  bitbot.buzz(1000);

  fiber_sleep(1000);

  bitbot.buzz(500);

  release_fiber();
}
