#include "kurzor.h"
#include <ncurses.h>

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

void kurzorConfig(){
    kurzorMark[kurzor]=' ';
    kurzor=0;
    kurzorMark[kurzor]='~';
    initscr();          //inicializece knihovny ncurses
    cbreak();           //vypnuti bufferu
    noecho();           //vypnuti vypisovani klavesnice
    clear();
}