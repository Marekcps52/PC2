#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "kurzor.h"
#include "info.h"
#include "seznam.h"

#define WELCOME "pro pohyb v menu pouzijte \n\
 w-nahoru \n \
s-dolu\n \
d- potvrzeni vyberu \n \
a- navrat zpet \n \
pro pokracovani stiskni cokoliv"


char kurzorMark[]="~    ";
int kurzor=0;

int main(){
    kurzorConfig();
    
    printw(WELCOME);            //uvitaci zprava, ceka na stisk klavesy
    getch();

    while(1){
        clear();
        printw("Seznam restauraci  %c \n",kurzorMark[0]);
        printw("radek %c \n",kurzorMark[1]);
        printw("info %c \n",kurzorMark[2]);
        printw("exit %c \n",kurzorMark[3]);
       // printw("\n\n\n h-help");e
        switch(getch()){
            case 's':
                kurzorDOWN();
                break;
            case 'w':
                kurzorUP();
                break;
            case 'e':               //exit
                endwin();           //ukonceni programu a reset nastaveni terminalu
                return 0;
            case 'i':
                printw(INFO);        
                break;
            case 'h':
                printw(WELCOME);            //uvitaci zprava, ceka na stisk klavesy
                getch();
            case 'd':                 //otevreni submenu
                switch(kurzor){
                    case 0:
                        seznam();
                        break;
                    case 1:
                        //volat 
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
