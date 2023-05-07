#include <stdio.h>
#include <stdlib.h>
#include "seznam.h"
#include "kurzor.h"
#include <ncurses.h>
//#include <dirent.h>
#include <string.h>

/*
typedef struct restaurace {
    char nazev[20];
    char adresa[10];
    char datum[20];
    int hvezdy;
    struct restaurace *dalsi;
} t_restaurace;
t_restaurace *restaurace[100];*/


void novaRestaurace(){
    endwin();
    system("clear");
    char vstup[20];
    
    printf("Zadejte nazev restaurace:\t");
    scanf("%s", vstup);
    fflush(stdin);
    strcat(vstup,".txt");
    FILE *fp;
    fp = fopen (vstup,"a+");
    if(fp==NULL){
        printf("Chyba souboru");
    }
    
    printf("Zadejte datum zalozeni:\t");
    scanf("%s", vstup);
    fflush(stdin);
    fputs(vstup,fp);
    fputs(";\n",fp); 
    system("clear");

    printf("Zadejte pocet hvezd:\t");
    scanf("%s",vstup);
    fflush(stdin);
    fputs(vstup,fp);
    fputs(";\n",fp);
    system("clear");
    
    kurzorConfig();
    fgets(vstup,20,fp);
    while(fgets(vstup,20,fp)!=NULL);{
        printw("%s",vstup);
    }
    
    getch();
    fclose(fp);
    return;


}