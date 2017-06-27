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

    For using timed functions like buzz(ms) it is important to initialize
    fiber:
    MicroBitMessageBus bus;
    scheduler_init(bus);
  */
  BitBot();

  /**
    @brief Buzz for a certain time, process blocks
    @param[in] buzz duration in microseconds
  */
  void buzz(float microseconds);

  /**
    @return light intensitiy as registered by left sensor (0 - 1023)
  */
  int lightLeft();

  /**
    @return light intensitiy as registered by right sensor (0 - 1023)
  */
  int lightRight();

  /**
    @return average of light intensities measured by the two sensors (0 - 1023)
  */
  int light() { return (lightLeft() + lightRight()) / 2; }

  /**
    @return light intensitiy as registered by left sensor in percent
  */
  float lightLeftPercent() { return (float)lightLeft() / MICROBIT_PIN_MAX_OUTPUT * 100; }

  /**
    @return light intensitiy as registered by right sensor in percent
  */
  float lightRightPercent() { return (float)lightRight() / MICROBIT_PIN_MAX_OUTPUT * 100; }

  /**
    @return average of light intensities measured by the two sensors in percent
  */
  float lightPercent() { return (float)light() / MICROBIT_PIN_MAX_OUTPUT * 100; }

  /**
    @returns whether left sensor registers a line
  */
  bool isLineLeft();

  /**
    @returns whether right sensor registers a line
  */
  bool isLineRight();
};
