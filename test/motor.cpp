#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "bitbot/motor.h"

// needed for fiber
MicroBitMessageBus bus;

int main()
{
  // Initialize bus for fiber
  scheduler_init(bus);

  Motor motor;

  motor.setLeftPercent(Direction::BACKWARDS, 50);
  fiber_sleep(1000);
  motor.setSpeedPercent(100, 100);
  fiber_sleep(1000);

  motor.stop();

  release_fiber();
}
