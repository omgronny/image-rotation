#ifndef LAB3_FILE_OPEN_CLOSE_H
#define LAB3_FILE_OPEN_CLOSE_H

#include "../image/image.h"

#include <stdbool.h>
#include <stdio.h>

bool file_open(const char* fileName, FILE** file, const char* mode);

bool file_close(FILE* file);

#endif //LAB3_FILE_OPEN_CLOSE_H
