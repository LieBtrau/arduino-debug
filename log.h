#ifndef debug_log_h
#define debug_log_h

#include <Arduino.h>

#define LOG_LEVEL 2

#ifndef LOG_LEVEL
#define LOG_LEVEL 2
#endif

#ifndef NLOG
static HardwareSerial* sPortDebug;
void LOG_INIT(HardwareSerial* port, word baud);

#  define LOGLN(...) sPortDebug->println(__VA_ARGS__)
#  define LOG(...) sPortDebug->print(__VA_ARGS__)

#define LOGVLN( var )                           \
   do                                           \
   {                                            \
      sPortDebug->println( var );               \
   }                                            \
   while( 0 )

#define LOGV( var )                             \
   do                                           \
   {                                            \
      sPortDebug->print( var );                 \
   }                                            \
   while( 0 )

void print(const byte* array, byte length);
#define debug_printArray(ARR,LEN) print(ARR,LEN)

#else

#define LOG_INIT( baud )
#define LOGLN(...) (void)0
#define LOG(...) (void)0
#define LOGVLN( var )
#define LOGV( var )
#define debug_printArray(ARR,LEN) ((void)0)


#endif

#endif
