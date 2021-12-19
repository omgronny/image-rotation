#ifndef LAB3_FILE_OPEN_CLOSE_H
#define LAB3_FILE_OPEN_CLOSE_H

#ifndef IMAGE_H
#define IMAGE_H
#include "../image/image.h"
#endif

#include <stdbool.h>
#include <stdio.h>

bool file_open(const char* fileName, FILE** file, const char* mode);

bool file_close(FILE* file);

#endif //LAB3_FILE_OPEN_CLOSE_H
