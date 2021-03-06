#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "bitbot/neopixel.h"

// needed for fiber
MicroBitMessageBus bus;

int main()
{
  // Initialize bus for fiber
  scheduler_init(bus);

  Neopixel np(MICROBIT_PIN_P13, 13);
  np.clear();

  fiber_sleep(2000);

  // returns 1 if index (here 9) was out of bounds
  np.showColor(9, 255, 0, 159);

  fiber_sleep(2000);

  np.clear();

  release_fiber();
}
