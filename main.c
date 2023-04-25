#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "kurzor.c"


int main(){
    initscr();          //inicializece knihovny ncurses
    cbreak();           //vypnuti bufferu
    noecho();           //vypnuti vypisovani klavesnice

    while(1){
        clear();
        printw("menu %c \n",kurzorMark[0]);
        printw("radek %c \n",kurzorMark[1]);
        printw("info %c \n",kurzorMark[2]);
        printw("exit %c \n",kurzorMark[3]);
        switch(getch()){
            case 's':
                kurzorMark[kurzor]=' ';
                kurzor++;
                kurzorMark[kurzor]='~';
                break;
            case 'w':
                kurzorUP();
                break;
            case 'c':
                endwin();           //ukonceni programu a reset nastaveni terminalu
                return 0;
        }
    }
    return 0;
}
