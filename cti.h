#ifndef _CTI_H_
#define _CTI_H_

#define MAX_NAZEV 50
#define MAX_ADRESA 100
#define MAX_KATEGORIE 30
#define MAX_LINE_LEN 50

struct Restaurant {
    char name[MAX_NAZEV];
    char address[MAX_ADRESA];
    char category[MAX_KATEGORIE];
    int review1;
    int review2;
};

void nactiSoubory();

#endif 
