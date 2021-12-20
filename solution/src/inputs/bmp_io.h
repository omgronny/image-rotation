#ifndef LAB3_BMP_IO_H
#define LAB3_BMP_IO_H

#include <malloc.h>
#include <stdint.h>

#include "../image/image.h"

struct __attribute__((packed)) bmp_header
{
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};

bool from_bmp(FILE* in, struct image* image);

bool to_bmp(FILE* out, const struct image* image);

#endif //LAB3_BMP_IO_H





