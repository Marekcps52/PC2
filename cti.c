#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "cti.h"

void nactiSoubory() {
    /*DIR* dir = opendir("./");
    struct dirent* entry;
    int filesRead = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char *ext = strrchr(entry->d_name, '.');
            if (ext && strcmp(ext, ".txt") == 0) {
                FILE *f = fopen(entry->d_name, "r");
                if (f != NULL) {
                    char line[1024];
                    while (fgets(line, sizeof(line), f) != NULL) {
                        struct Restaurant newRest;
                        char *token;
                        int i = 0;
                        token = strtok(line, "\t\n");
                        while (token != NULL) {
                            switch (i) {
                                case 0:
                                    strcpy(newRest.name, token);
                                    break;
                                case 1:
                                    strcpy(newRest.address, token);
                                    break;
                                case 2:
                                    newRest.rating = atof(token);
                                    break;
                                case 3:
                                    newRest.review1 = atoi(token);
                                    break;
                                case 4:
                                    newRest.review2 = atoi(token);
                                    break;
                                case 5:
                                    newRest.review3 = atoi(token);
                                    break;
                                default:
                                    break;
                            }
                            token = strtok(NULL, "\t\n");
                            i++;
                        }
                        printf("%s %s %.1f %d %d %d\n", newRest.name, newRest.address, newRest.rating, newRest.review1, newRest.review2, newRest.review3);
                    }
                    fclose(f);
                    filesRead++;
                } else {
                    printf("Error: Unable to open file %s\n", entry->d_name);
                }
            }
        }
    }

    closedir(dir);
    printf("Number of files read: %d\n", filesRead);
    printf("Press any key to continue...");
    getchar();*/
}
