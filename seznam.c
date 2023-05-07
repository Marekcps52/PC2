#include <stdio.h>
#include <stdlib.h>
#include "seznam.h"
#include "kurzor.h"
#include <ncurses.h>
#include <string.h>
#include <dirent.h>

char blank;
int h;

typedef struct recenze{
    char autor[20];
    char text[200];
    int hodnoceni;
}t_recenze;

typedef struct restaurace {
    char nazev[20];
    char adresa[10];
    char datum[20];
    int hvezdy;
    t_recenze *recenze[20];
    struct restaurace *dalsi;
} t_restaurace;

t_restaurace *restaurace[100];

void seznam(){

    for(int i=0;i<100;i++){             //promazani jiz existujicich zaznamu
    if(restaurace[i]!=NULL){
        for(int j=0; j<20; j++){   // free memory for recenze structures
            free(restaurace[i]->recenze[j]);
        }
        free(restaurace[i]);
        restaurace[i]=NULL;
    }
}


    clear();                                            //otevreni souboru
    int active=0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(".");

    while((entry=readdir(dir)) != NULL){                                //nacteni aktualnich zaznamu
        if(strstr(entry->d_name, ".txt") != NULL){
            t_restaurace* nova = (t_restaurace *) malloc(sizeof(t_restaurace));
            FILE *fp;
            fp = fopen(entry->d_name, "r");

            fscanf(fp,"%s",nova->nazev);
            fscanf(fp,"%s",nova->adresa);
            fscanf(fp,"%s",nova->datum);
            fscanf(fp,"%d",&(nova->hvezdy));
            for (int j=0; j<20;j++){
                if(!feof(fp)){
                    nova->recenze[j]=(t_recenze *) malloc(sizeof(t_recenze));
                    fscanf(fp, "%s", nova->recenze[j]->autor);
                    while (fscanf(fp, "%c", &blank) == 1 && blank != ';') {
                        nova->recenze[j]->text[h++] = blank;
                    }  
                    nova->recenze[j]->text[h] = '\0';
                    h=0;
                    
                    fscanf(fp, "%d", &(nova->recenze[j]->hodnoceni));
                }
            }
            
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

    if(restaurace[0]==NULL) {
        printw("zadne zaznamy!!!");
        getch();
        return;
        }

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
                while(1){
                        clear();
                        printw("%s \n", restaurace[kurzor]->nazev);
                        printw("Adresa: %s \n", restaurace[kurzor]->adresa);
                        printw("Datum zalozeni: %s\n", restaurace[kurzor]->datum);
                        printw("pocet hvezd: %d\n\n", restaurace[kurzor]->hvezdy);
                            for (int j=0; j<20;j++){
                                if(restaurace[kurzor]->recenze[j]!=NULL)   { 
                                    printw("Autor: %s:\t", restaurace[kurzor]->recenze[j]->autor);
                                    printw("%s\n", restaurace[kurzor]->recenze[j]->text);
                                    printw("Hodnoceni: %d/10\n\n", restaurace[kurzor]->recenze[j]->hodnoceni);
                                }
                            }
                        printw("a-navrat, r-nova recenze");
                        switch(getch()){
                            case 'a':
                                return;
                            case 'r':
                                
                                clear();
                                char soubor[20]={0};
                                strcpy(soubor,restaurace[kurzor]->nazev);
                                strcat(soubor,".txt");
                                FILE *fp;
                                fp=fopen(soubor,"a+");
                                 if(fp==NULL){
                                    printw("Chyba souboru");
                                }
                                char vstup[100];
                                
                                printw("Zadejte sve jmeno:\t");
                                scanf("%s", vstup);
                                fflush(stdin);
                                fputs(vstup,fp);
                                fputs("\n",fp); 
                                system("clear");

                                char buffer[100];
                                int i=0;
                                endwin();
                                printf("Zadejte text recenze ukonceny strednikem ';':\t");
                                while(1){
                                    int c=getchar();
                                    if (c==';'){
                                        buffer[i]='\0';
                                        break;
                                    }
                                    buffer[i++]=c;
                                }
                                
                                
                                fclose(fp);
                                system("clear");
                                
                                
                                return;


                        }
                }
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
