#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "bitbot/bitbot.h"

MicroBitMessageBus bus;
BitBot bitbot;

int main()
{
  scheduler_init(bus);

  for (; true; fiber_sleep(100)) {
    if (bitbot.isLineLeft()) {
      bitbot.buzz(100);
    }
  }

  release_fiber();
}
