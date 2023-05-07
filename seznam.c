#include <stdio.h>
#include <stdlib.h>
#include "seznam.h"
#include "kurzor.h"
#include <ncurses.h>
#include <string.h>
#include <dirent.h>

typedef struct restaurace {
    char nazev[20];
    char adresa[10];
    char datum[20];
    int hvezdy;
    struct restaurace *dalsi;
} t_restaurace;
t_restaurace *restaurace[100];

void seznam(){

    for(int i=0;i<100;i++){             //promazani jiz existujicich zaznamu
    if(restaurace[i]!=NULL){
        free(restaurace[i]);
        restaurace[i]=NULL;
        }
    }

    clear();                             //nacteni aktualnich zaznamu
    int active=0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");
    while((entry=readdir(dir)) != NULL){
        if(strstr(entry->d_name, ".txt") != NULL){
            t_restaurace *nova = (t_restaurace *) malloc(sizeof(t_restaurace));
            FILE *fp;
            fp = fopen(entry->d_name, "r");
            fscanf(fp,"%s",nova->nazev);
            fscanf(fp,"%s",nova->adresa);
            fscanf(fp,"%s",nova->datum);
            fscanf(fp,"%d",&(nova->hvezdy));
            fclose(fp);

            for(int i=0;i<100;i++){
                if(restaurace[i]==NULL){
                    restaurace[i]=nova;
                    break;
                }
            }
            
        }
    }
    closedir(dir);
    
    //endwin();

    kurzorConfig();
    while(1){
        clear();
        active=0;
        for(int i=0;i<100;i++){
            if (restaurace[i] != NULL){
                active++;
                printw(" %s %c \n", restaurace[i]->nazev,kurzorMark[i]);
                }
            }
        max_radky=active-1;
        switch(getch()){
            case 's':
                kurzorDOWN();
                break;
            case'w':
                kurzorUP();
                break;
            case'a':
                return;
            case'd':
                //switch(kurzor){
                    //case 0:
                        clear();
                        printw("%s: \n", restaurace[kurzor]->nazev);
                        printw("Adresa: %s \n", restaurace[kurzor]->adresa);
                        printw("Datum zalozeni: %s\n", restaurace[kurzor]->datum);
                        printw("pocet hvezd: %d\n\n,", restaurace[kurzor]->hvezdy);
                        getch();
                    //case 'a':
                      //  return;
                //}
        }
    }
    return;
 
}


void novaRestaurace(){
    endwin();
    system("clear");
    char vstup[20];
    char priponou[24];
    
    printf("Zadejte nazev restaurace:\t");
    scanf("%s", vstup);
    fflush(stdin);
    strcpy(priponou,vstup);
    strcat(priponou,".txt");
    FILE *fp;
    fp = fopen (priponou,"a+");
    if(fp==NULL){
        printf("Chyba souboru");
    }

    
    fputs(vstup,fp);
    fputs("\n",fp); 
    system("clear");
    
    printf("Zadejte datum zalozeni:\t");
    scanf("%s", vstup);
    fflush(stdin);
    fputs(vstup,fp);
    fputs("\n",fp); 
    system("clear");

    printf("Zadejte pocet hvezd:\t");
    scanf("%s",vstup);
    fflush(stdin);
    fputs(vstup,fp);
    fputs("\n",fp);
    system("clear");
    
    kurzorConfig();
    fgets(vstup,20,fp);
    char buffer[100]={0};
    fgets(buffer,100,fp);
    printw("%s",buffer);
    fclose(fp);
    endwin();
    return;


}
