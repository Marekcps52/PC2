#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "kurzor.h"
#include "info.h"

#define WELCOME "pro pohyb v menu pouzijte w-nahoru \n \
s-dolu\n \
d- potvrzeni vyberu \n \
a- navrat zpet \n \
pro pokracovani stiskni cokoliv"


char kurzorMark[]="~    ";
int kurzor=0;

int main(){
    initscr();          //inicializece knihovny ncurses
    cbreak();           //vypnuti bufferu
    noecho();           //vypnuti vypisovani klavesnice
    clear();
    
    printw(WELCOME);
    // while(1){
    //     if(getch()=='\n')
    //     break;
    // }
    getch();

    while(1){
        clear();
        printw("menu %c \n",kurzorMark[0]);
        printw("radek %c \n",kurzorMark[1]);
        printw("info %c \n",kurzorMark[2]);
        printw("exit %c \n",kurzorMark[3]);
        switch(getch()){
            case 's':
                kurzorDOWN();
                break;
            case 'w':
                kurzorUP();
                break;
            case 'c':
                endwin();           //ukonceni programu a reset nastaveni terminalu
                return 0;
            case 'i':
                printw(INFO);
                break;
            case 'd':
                switch(kurzor){
                    case 2:
                    info();
                    break;
                    case 3:
                    endwin();
                    return 0;

                }
        }
    }
    return 0;
}
