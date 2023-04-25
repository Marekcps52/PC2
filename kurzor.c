#include <stdlib.h>

char kurzorMark[]="~     ";
int kurzor=0;

void kurzorUP(){
    kurzorMark[kurzor]=' ';
                kurzor--;
                kurzorMark[kurzor]='~';
}