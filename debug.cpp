#include "debug.h"

#ifdef DEBUG
void openDebug(word baud)
{
    while (!(*sPortDebug));
    sPortDebug->begin(baud);
}


void print(const byte* array, byte length)
{
    sPortDebug->print("Length = ");sPortDebug->println(length,DEC);
    for (byte i = 0; i < length; i++)
    {
	sPortDebug->print(array[i], HEX);
	sPortDebug->print(" ");
        if ((i + 1) % 16 == 0)
        {
	    sPortDebug->println();
        }
    }
    sPortDebug->println();
}

#endif


