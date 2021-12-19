#include "bmp_io.h"
#include "stdint.h"
#include <stdbool.h>

static size_t size_of_padding(const size_t width) {

    if (width % 4 == 0) {
        return 0;
    }
    return 4 - ((width * sizeof(struct pixel)) % 4);

}

static bool head_read(FILE* file, struct bmp_header* header) {
    return fread(header, sizeof(struct bmp_header), 1, file);
}

static size_t size_of_image(const struct image* image) {
    return (image->width * sizeof(struct pixel) + size_of_padding(image->width)) * image->height;
}

static size_t size_of_file(const struct image* image) {
    return size_of_image(image) + sizeof(struct bmp_header);
}

static struct bmp_header create_header(const struct image *image) {
    return (struct bmp_header) {
            .bfType = 19778,
            .bfileSize = size_of_file(image),
            .bfReserved = 0,
            .bOffBits = 54,
            .biSize = 40,
            .biWidth = image->width,
            .biHeight = image->height,
            .biPlanes = 1,
            .biBitCount = 24,
            .biCompression = 0,
            .biSizeImage = size_of_image(image),
            .biXPelsPerMeter = 0,
            .biYPelsPerMeter = 0,
            .biClrUsed = 0,
            .biClrImportant = 0
    };
}


bool from_bmp(FILE* in, struct image* image) {

    struct bmp_header header = {0};
    if (!head_read(in, &header)) {
        return false;
    }

    //size_t size = size_of_padding(image->width);
    *image = image_create(header.biWidth, header.biHeight);

    const size_t padding = size_of_padding(image->width);

    for (size_t i = 0; i < image->height; ++i) {
        for (size_t j = 0; j < image->width; ++j) {
            fread(&(image->data[image->width * i + j]), sizeof(struct pixel), 1, in);
        }
        fseek(in, padding, SEEK_CUR);
    }

    return true;
}

bool to_bmp(FILE* out, const struct image* image) {

    struct bmp_header header = create_header(image);

    if (!fwrite(&header, sizeof(struct bmp_header), 1, out)) {
        return false;
    }

    fseek(out, header.bOffBits, SEEK_SET);

    const int8_t zero = 0;

    const size_t padding = size_of_padding(image->width);

    if (image->data != NULL) {
        for (size_t i = 0; i < image->height; ++i) {

            fwrite(image->data + i * image->width, image->width * sizeof(struct pixel), 1, out);

            for (size_t j = 0; j < padding; ++j) {
                fwrite(&zero, 1, 1, out);
            }

        }
    } else {
        return false;
    }

    return true;

}



