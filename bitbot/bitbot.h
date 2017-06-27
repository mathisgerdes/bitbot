#include "MicroBitMessageBus.h"
#include "MicroBitFiber.h"
#include "bitbot/motor.h"
#include "bitbot/neopixel.h"

class BitBot {
public:
  Motor motor;
  Neopixel neopixel;

  struct {
    MicroBitPin buzzer;
    MicroBitPin light_sensor;
    MicroBitPin light_sensor_control;
    MicroBitPin line_sensor_left;
    MicroBitPin line_sensor_right;
  } pins;

  // event management
  MicroBitMessageBus message_bus;

  /**
    @brief Create Bit:Bot instance

    It is importent to initializ the bitbot instance before any other
    microbit components as otherwise the bus/fiber system might break
  */
  BitBot();

  /**
    @brief Buzz for a certain time, process blocks
    @param[in] buzz duration in microseconds
  */
  void buzz(float microseconds);
};
