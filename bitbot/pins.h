#pragma once

#include "MicroBitComponent.h"
#include "MicroBitPin.h"

/**
  @brief Get the event-handling id given a pin name
  @param[in] pin name (e.g. MICROBIT_PIN_P6)
  @return pin IO ID (e.g. MICROBIT_ID_IO_P6)
  @rtval 0 Pin was not found (no events)
*/
constexpr inline int getIoId(PinName pin)
{
  return pin==MICROBIT_PIN_P0 ? MICROBIT_ID_IO_P0:
         pin==MICROBIT_PIN_P1 ? MICROBIT_ID_IO_P1:
         pin==MICROBIT_PIN_P2 ? MICROBIT_ID_IO_P2:
         pin==MICROBIT_PIN_P3 ? MICROBIT_ID_IO_P3:
         pin==MICROBIT_PIN_P4 ? MICROBIT_ID_IO_P4:
         pin==MICROBIT_PIN_P5 ? MICROBIT_ID_IO_P5:
         pin==MICROBIT_PIN_P6 ? MICROBIT_ID_IO_P6:
         pin==MICROBIT_PIN_P7 ? MICROBIT_ID_IO_P7:
         pin==MICROBIT_PIN_P8 ? MICROBIT_ID_IO_P8:
         pin==MICROBIT_PIN_P9 ? MICROBIT_ID_IO_P9:
         pin==MICROBIT_PIN_P10 ? MICROBIT_ID_IO_P10:
         pin==MICROBIT_PIN_P11 ? MICROBIT_ID_IO_P11:
         pin==MICROBIT_PIN_P12 ? MICROBIT_ID_IO_P12:
         pin==MICROBIT_PIN_P13 ? MICROBIT_ID_IO_P13:
         pin==MICROBIT_PIN_P14 ? MICROBIT_ID_IO_P14:
         pin==MICROBIT_PIN_P15 ? MICROBIT_ID_IO_P15:
         pin==MICROBIT_PIN_P16 ? MICROBIT_ID_IO_P16:
         pin==MICROBIT_PIN_P19 ? MICROBIT_ID_IO_P19:
         pin==MICROBIT_PIN_P20 ? MICROBIT_ID_IO_P20: 0;
}
