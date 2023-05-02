#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "cti.h"

#define MAX_NAMES 20
#define MAX_FILENAME_LEN 100

typedef struct {
    char name[MAX_FILENAME_LEN];
} Filename;

void nactiSoubory() { 
    
    DIR* dir = opendir("./");
    struct dirent* entry;
    Filename filenames[MAX_NAMES];
    int count = 0;

    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir)) != NULL && count < MAX_NAMES) {
        if (strstr(entry->d_name, "REST") != NULL) {
            strcpy(filenames[count].name, entry->d_name);
            count++;
        }
    }

    closedir(dir);

    // Print out the saved filenames
    for (int i = 0; i < count; i++) {
        printf("%s\n", filenames[i].name);
    }

    return 0;
}
