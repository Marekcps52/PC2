#include <stdio.h>
#include <dirent.h>
#include <string.h>

int main() {
    DIR *d;
    struct dirent *dir;
    char extension[] = ".csv";
    
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            if (strstr(dir->d_name, extension) != NULL) {
                printf("%s\n", dir->d_name);
            }
        }
        closedir(d);
    }
    
    return 0;
}
