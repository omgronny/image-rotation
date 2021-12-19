#include "file_open_close.h"

#include <errno.h>
#include <stdio.h>

bool file_open(const char* fileName, FILE** file, const char* mode) {

    *file = fopen(fileName, mode);

    if (file == NULL) {
        printf("Error: %d\n", errno);
        return false;
    }

    return true;

}

bool file_close(FILE* file) {
    if (fclose(file) == EOF) {
        return false;
    }
    return true;
}
