#include "seznam.h"
#include "kurzor.h"
void seznam(){

    kurzorConfig();
    
    while(1){
        clear();
        printw();
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
            case 'd' :
                switch(kurzor){
                    case 1 :

                }
        }
    }
}
