#include "gpiote.h"


void gpiote_setup()
{
    GPIOTE->CONFIG[0] = 0b100100001000100000001; //channel 0 set to event, falling edge, button A

    GPIOTE->CONFIG[1] = 0b100110000110100000011; //channels 1-3 set to task, pins 13-15 (LED matrix source), toggle
    GPIOTE->CONFIG[2] = 0b100110000111000000011; 
    GPIOTE->CONFIG[3] = 0b100110000111100000011; 
}