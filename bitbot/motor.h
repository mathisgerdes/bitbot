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
    Direction dir_left, dir_right;
    int speed_left, speed_right;
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

  /**
    @brief Set direction, and speed for each side
    @param[in] direction
    @param[in] speed of left wheel; range [0,1023]
    @param[in] speed of right wheel; range [0,1023]
  */
  void setSpeed(Direction dir, int speed_left, int speed_right);

  /**
    @brief Set speed for each side and infer direction from sign
    @param[in] speed of left wheel; range [-1023, 1023]
    @param[in] speed of right wheel; range [-1023, 1023]
  */
  void setSpeed(int speed_left, int speed_right);

  /**
    @brief Move straight at a given velocity
    @param[in] speed where negative implies backwards; range [-1023, 1023]
  */
  void setSpeed(int speed);

  /**
    @brief Set direction, and speed for each side in percent
    @param[in] direction
    @param[in] speed of left wheel; range [0.0,100.0]
    @param[in] speed of right wheel; range [0.0,100.0]
  */
  void setSpeedPercent(Direction dir, float speed_left, float speed_right);

  /**
    @brief Set speed for each side in percent and infer direction from sign
    @param[in] speed of left wheel in percent; range [-100.0, 100.0]
    @param[in] speed of right wheel in percent; range [-100.0, 100.0]
  */
  void setSpeedPercent(float speed_left, float speed_right);

  /**
    @brief Move straight at a given velocity
    @param[in] speed where negative implies backwards; range [-1023, 1023]
  */
  void setSpeedPercent(float speed);

  /**
    @return current speed of left wheel in range [0, 1023]
  */
  int getSpeedLeft();

  /**
    @return current speed of left wheel in percent
  */
  float getSpeedLeftPercent();

  /**
    @return current direction of left wheel
  */
  Direction getDirectionLeft();

  /**
    @return current speed of right wheel in range [0, 1023]
  */
  int getSpeedRight();

  /**
    @return current speed of right wheel in percent
  */
  float getSpeedRightPercent();

  /**
    @return current direction of right wheel
  */
  Direction getDirectionRight();
};
