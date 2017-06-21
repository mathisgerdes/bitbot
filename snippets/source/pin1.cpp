#include "MicroBit.h"

MicroBitPin pin0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_DIGITAL);
MicroBitPin pin1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_DIGITAL);

// needed for fiber
MicroBitMessageBus bus;

int main()
{
  // initialize fiber
  scheduler_init(bus);

  int state{0};
  while (true) {
    state = !state;

    pin0.setDigitalValue(state);

    fiber_sleep(1000);
  }
}
