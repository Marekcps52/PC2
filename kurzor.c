#include "kurzor.h"

void kurzorUP(){
    kurzorMark[kurzor]=' ';
    kurzor--;
    if(kurzor<MIN_RADKY)
        kurzor=MAX_RADKY;
    kurzorMark[kurzor]='~';
}

void kurzorDOWN(){
    kurzorMark[kurzor]=' ';
    kurzor++;
    if(kurzor>MAX_RADKY)
        kurzor=MIN_RADKY;
    kurzorMark[kurzor]='~';
}

