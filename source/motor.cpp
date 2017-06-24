#include <algorithm> // min, max
#include "bitbot/motor.h"

Motor::Motor(PinName left_dir, PinName left_speed,
             PinName right_dir, PinName right_speed)
  : pins {MicroBitPin(getIoId(left_dir), left_dir, PIN_CAPABILITY_DIGITAL_OUT),
          MicroBitPin(getIoId(left_speed), left_speed, PIN_CAPABILITY_ANALOG_OUT),
          MicroBitPin(getIoId(right_dir), right_dir, PIN_CAPABILITY_DIGITAL_OUT),
          MicroBitPin(getIoId(right_speed), right_speed, PIN_CAPABILITY_ANALOG_OUT)},
    state {}
{ }

Motor::~Motor()
{
  // make sure motor stops if object is destroyed, so robot doesn't get
  // out of control
  stop();
}

inline void setMotorPins(MicroBitPin& pin_dir, Direction dir,
                         MicroBitPin& pin_speed, int speed)
{
  // limit speed to minimal/maximal values
  speed = std::max(0, std::min(MICROBIT_PIN_MAX_OUTPUT, speed));
  // calculate actual analog value, considering the direction
  speed = (dir == Direction::FORWARDS) ? speed : MICROBIT_PIN_MAX_OUTPUT - speed;
  // write direction & speed
  pin_dir.setDigitalValue(static_cast<int>(dir));
  pin_speed.setAnalogValue(speed);
}

void Motor::setLeft(Direction dir, int speed)
{
  setMotorPins(pins.left_dir, dir, pins.left_speed, speed);
  state.left_dir = dir;
  state.left_speed = speed;
}

void Motor::setRight(Direction dir, int speed)
{
  setMotorPins(pins.right_dir, dir, pins.right_speed, speed);
  state.right_dir = dir;
  state.right_speed = speed;
}

void Motor::setLeftPercent(Direction dir, float speed)
{
  setLeft(dir, static_cast<int>(speed / 100 * MICROBIT_PIN_MAX_OUTPUT));
}

void Motor::setRightPercent(Direction dir, float speed)
{
  setRight(dir, static_cast<int>(speed / 100 * MICROBIT_PIN_MAX_OUTPUT));
}

void Motor::stop()
{
  setLeft(Direction::FORWARDS, 0);
  setRight(Direction::FORWARDS, 0);
}
