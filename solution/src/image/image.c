#include "image.h"
#include <malloc.h>

struct image some_image(uint64_t width, uint64_t height, struct pixel *data) {
    return (struct image) {.width = width, .height = height, .data = data};
}

struct image image_create(const size_t image_width, const size_t image_height) {

    struct pixel* pixels = malloc(sizeof(struct pixel) * image_width * image_height );

    return some_image(image_width, image_height, pixels);


}

struct image copy(struct image image) {

    struct pixel* pixels = malloc(sizeof(struct pixel) * image.width * image.height );

    for (size_t i = 0; i < image.height * image.width; ++i) {
        pixels[ i ] = image.data [ i ];
    }

    return some_image(image.width, image.height, pixels);

}

void image_destroy(struct image* image) {
    free(image->data);
}
