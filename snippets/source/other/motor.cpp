#include "MicroBit.h"

// Left motor: Speed Pin 0, Direction, Pin 8
// Right motor: Speed Pin 1, Direction Pin 12
// max forward: speed 1, direction 0
// max backward: speed 0, direction 1
MicroBitPin pin0(MICROBIT_ID_IO_P0, MICROBIT_PIN_P0, PIN_CAPABILITY_ALL);
MicroBitPin pin8(MICROBIT_ID_IO_P8, MICROBIT_PIN_P8, PIN_CAPABILITY_ALL);
MicroBitPin pin1(MICROBIT_ID_IO_P1, MICROBIT_PIN_P1, PIN_CAPABILITY_ALL);
MicroBitPin pin12(MICROBIT_ID_IO_P12, MICROBIT_PIN_P12, PIN_CAPABILITY_ALL);

// needed for fiber
MicroBitMessageBus bus;

int main() {
  scheduler_init(bus);

  int power = 200;

  while (true) {
    pin8.setDigitalValue(0);
    pin0.setAnalogValue(power);
    pin12.setDigitalValue(0);
    pin1.setAnalogValue(power);
    fiber_sleep(500);
    pin0.setAnalogValue(0);
    pin1.setAnalogValue(0);
    fiber_sleep(500);
    pin8.setDigitalValue(1);
    pin0.setAnalogValue(1023 - power);
    pin12.setDigitalValue(1);
    pin1.setAnalogValue(1023 - power);
    fiber_sleep(500);
  }

  release_fiber();
}
