#include "bitbot/bitbot.h"

BitBot::BitBot()
  : motor(),
    neopixel {Neopixel(MICROBIT_PIN_P13, 13)},
    pins {
      // buzzer (1 - on)
      MicroBitPin(MICROBIT_ID_IO_P14, MICROBIT_PIN_P14, PIN_CAPABILITY_DIGITAL_OUT),
      // light sensor (higher value - brighter; max 1023)
      MicroBitPin(MICROBIT_ID_IO_P2, MICROBIT_PIN_P2, PIN_CAPABILITY_ANALOG_IN),
      // light sensor selector (0 - left, 1 - right)
      MicroBitPin(MICROBIT_ID_IO_P16, MICROBIT_PIN_P16, PIN_CAPABILITY_DIGITAL_OUT),
      // line dectector left (1 - detected)
      MicroBitPin(MICROBIT_ID_IO_P11, MICROBIT_PIN_P11, PIN_CAPABILITY_DIGITAL_IN),
      // line dectector right (1 - detected)
      MicroBitPin(MICROBIT_ID_IO_P5, MICROBIT_PIN_P5, PIN_CAPABILITY_DIGITAL_IN)
    },
    message_bus()
{
  // Initialize fiber scheduler so sleep is enabled
  scheduler_init(message_bus);
}


void BitBot::buzz(float microseconds)
{
  pins.buzzer.setDigitalValue(1);
  fiber_sleep(microseconds);
  pins.buzzer.setDigitalValue(0);
}
