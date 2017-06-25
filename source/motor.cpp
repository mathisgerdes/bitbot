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
  state.dir_left = dir;
  state.speed_left = speed;
}

void Motor::setRight(Direction dir, int speed)
{
  setMotorPins(pins.right_dir, dir, pins.right_speed, speed);
  state.dir_right = dir;
  state.speed_right = speed;
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

void Motor::setSpeed(Direction dir, int speed_left, int speed_right)
{
  setLeft(dir, speed_left);
  setRight(dir, speed_right);
}

void Motor::setSpeed(int speed_left, int speed_right)
{
  if (speed_left >= 0) {
    setLeft(Direction::FORWARDS, speed_left);
  } else {
    setLeft(Direction::BACKWARDS, -speed_left);
  }

  if (speed_right >= 0) {
    setRight(Direction::FORWARDS, speed_right);
  } else {
    setRight(Direction::BACKWARDS, -speed_right);
  }
}

void Motor::setSpeed(int speed)
{
  Direction dir {Direction::FORWARDS};
  if (speed < 0) {
    dir = Direction::BACKWARDS;
    speed = -speed;
  }
  setLeft(dir, speed);
  setRight(dir, speed);
}

void Motor::setSpeedPercent(Direction dir, float speed_left, float speed_right)
{
  setLeftPercent(dir, speed_left);
  setRightPercent(dir, speed_right);
}

void Motor::setSpeedPercent(float speed_left, float speed_right)
{
  if (speed_left >= 0) {
    setLeftPercent(Direction::FORWARDS, speed_left);
  } else {
    setLeftPercent(Direction::BACKWARDS, -speed_left);
  }

  if (speed_right >= 0) {
    setRightPercent(Direction::FORWARDS, speed_right);
  } else {
    setRightPercent(Direction::BACKWARDS, -speed_right);
  }
}

void Motor::setSpeedPercent(float speed)
{
  Direction dir {Direction::FORWARDS};
  if (speed < 0) {
    dir = Direction::BACKWARDS;
    speed = -speed;
  }
  setLeftPercent(dir, speed);
  setRightPercent(dir, speed);
}

int Motor::getSpeedLeft()
{
  return state.speed_left;
}

float Motor::getSpeedLeftPercent()
{
  return state.speed_left / 100.0;
}

Direction Motor::getDirectionLeft()
{
  return state.dir_left;
}

int Motor::getSpeedRight()
{
  return state.speed_right;
}

float Motor::getSpeedRightPercent()
{
  return state.speed_right / 100.0;
}

Direction Motor::getDirectionRight()
{
  return state.dir_right;
}
