#include "info.h"


void info(){
    while(1){
        clear();
        printw(INFO);
        if(getch()=='a')
        break;
    }
}