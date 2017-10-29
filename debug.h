#ifndef DEBUG_H
#define DEBUG_H

#include "Arduino.h"

#define DEBUG
//https://stackoverflow.com/questions/1644868/c-define-macro-for-debug-printing

#ifdef DEBUG
#  if defined(ARDUINO_AVR_PROTRINKET3FTDI) || defined(ARDUINO_AVR_PROTRINKET3)
#  include <SoftwareSerial.h>
static SoftwareSerial swSer(A5,A4);//RX, TX
static SoftwareSerial* sPortDebug = &swSer;
#  elif defined(ARDUINO_STM_NUCLEO_F103RB) || defined(ARDUINO_GENERIC_STM32F103C) || defined(ARDUINO_SAM_DUE)
static HardwareSerial* sPortDebug = &Serial;
#  else
#  error Unsupported target device
#  endif
void openDebug(word baud);
void print(const byte* array, byte length);
#  define debug_printArray(ARR,LEN) print(ARR,LEN)
#  define debug_println(...) sPortDebug->println(__VA_ARGS__)
#  define debug_print(...) sPortDebug->print(__VA_ARGS__)
#
#else//ifdef DEBUG
#
#  define debug_println(...) (void)0
#  define debug_print(...) (void)0
#  define openDebug(...) (void)0
#  define debug_printArray(ARR,LEN) ((void)0)
#endif//ifdef DEBUG

#endif // DEBUG_H

