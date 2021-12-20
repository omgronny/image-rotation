#ifndef LAB3_IMAGE_H
#define LAB3_IMAGE_H

#include <stdbool.h>
#include <stdint.h>

struct pixel {
    uint8_t b;
    uint8_t g;
    uint8_t r;
};

struct image {
    uint64_t width;
    uint64_t height;
    struct pixel *data;
};

struct image some_image(uint64_t width, uint64_t height, struct pixel *data);
struct image image_create(uint64_t image_width, uint64_t image_height);
struct image copy(struct image image);
void image_destroy(struct image* image);

#endif //ASSIGNMENT_IMAGE_ROTATION_IMAGE_H

