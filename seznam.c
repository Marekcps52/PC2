#include "seznam.h"
#include "kurzor.h"
#include <dirent.h>
#include <string.h>
//#include "vypis.h"

void seznam(){
    int pocetSouboru=0;
    char nazvy[100][20]={0};
    DIR *dir;
    struct dirent *entry;
    kurzorConfig();
    
    dir = opendir(".");
    if (dir == NULL)
        printw("zaznamy nenalezeny!");
    
    while((entry=readdir(dir))!= NULL)
        {
        if(strstr(entry->d_name, "R:") != NULL){
            printw("%s \n", entry->d_name);
            strcpy(nazvy[pocetSouboru],entry->d_name);
            pocetSouboru++;
        }
    }
    printw("nalezeno %d souboru",pocetSouboru);
    closedir(dir);
    getch();
    kurzorConfig();
    max_radky=pocetSouboru-1;

    while(1){
        clear();
        for(int i=0;i<pocetSouboru;i++){
          printw("%s gn  %c\n",nazvy[i],kurzorMark[i]);
        }
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
                vypis(nazvy);
                
                break;
        }
    }

}