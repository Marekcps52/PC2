#include "seznam.h"
#include "kurzor.h"
void seznam(){

    kurzorConfig();
    printw("seznam... %c \n", kurzorMark[0]);
    printw("seznam... %c \n", kurzorMark[0]);
    printw("seznam... %c \n", kurzorMark[0]);
    printw("seznam... %c \n", kurzorMark[0]);
    while(1){
        switch(getch()){
            case 's':
                kurzorDOWN();
                break;
            case 'w':
                kurzorUP();
                break;
            case 'a':
                endwin();
                return;
        }
    }
}
