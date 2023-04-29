#include "seznam.h"
#include "kurzor.h"
void seznam(){

    kurzorConfig();
    
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
