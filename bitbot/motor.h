#pragma once

#include "bitbot/pins.h"

enum Direction : int {
  FORWARDS = 0,
  BACKWARDS = 1
};

/**
  Class for controlling the motor(s) (i.e. the movement) of the bitbot
*/
class Motor {
private:
  struct {
    MicroBitPin left_dir, left_speed, right_dir, right_speed;
  } pins;
  struct {
    Direction left_dir, right_dir;
    int left_speed, right_speed;
  } state;
public:
  /**
    @brief Initialize Motor with the control pins
    @param[in] name of the pin controlling the direction
        of the left motor (e.g. MICROBIT_PIN_P9)
  	@param[in] name of the pin controlling the speed of the left motor
    @param[in] name of the pin controlling the direction of the right motor
    @param[in] name of the pin controlling the speed of the right motor
  */
  Motor(PinName left_dir = MICROBIT_PIN_P8, PinName left_speed = MICROBIT_PIN_P0,
        PinName right_dir = MICROBIT_PIN_P12, PinName right_speed = MICROBIT_PIN_P1);

  ~Motor();

  /**
    @brief Set direction and speed of the left motor
    @param[in] direction
    @param[in] speed (0-MICROBIT_PIN_MAX_OUTPUT (1023)) of the moter,
        higher values mean faster
  */
  void setLeft(Direction dir, int speed);

  /**
  @brief Set direction and speed of the right motor
  @param[in] direction
  @param[in] speed (0-MICROBIT_PIN_MAX_OUTPUT (1023)) of the moter,
  higher values mean faster
  */
  void setRight(Direction dir, int speed);
  /**

    @brief Set direction and speed of the left motor
    @param[in] direction
    @param[in] speed of the moter in percent (0.0-100.0)
  */
  void setLeftPercent(Direction dir, float speed);

  /**
    @brief Set direction and speed of the right motor
    @param[in] direction
    @param[in] speed of the moter in percent (0.0-100.0)
  */
  void setRightPercent(Direction dir, float speed);

  /**
    @brief Stop moving
  */
  void stop();
};
