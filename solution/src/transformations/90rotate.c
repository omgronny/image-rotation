#include "90rotate.h"
#include <malloc.h>

static struct image rotate_90_degrees( const struct image source, struct pixel *pixels ) {

    for (size_t i = 0; i < source.height; ++i) {
        for (size_t j = 0; j < source.width; ++j) {
            //pixels[ source.width * j + i ] = source.data [ source.height * (source.height - 1 - i) + j];
            pixels[source.height * j + (source.height - 1 - i) ] = source.data [i * source.width + j];
        }
    }

    return some_image(source.height, source.width, pixels);

}

static struct image rotate_180_degrees( const struct image source, struct pixel *pixels ) {

    for (size_t i = 0; i < source.height * source.width; ++i) {
        pixels[ i ] = source.data [ source.height * source.width - i - 1 ];
    }

    return some_image(source.width, source.height, pixels);

}

static struct image rotate_270_degrees( const struct image source, struct pixel *pixels ) {

    for (size_t i = 0; i < source.height; ++i) {
        for (size_t j = 0; j < source.width; ++j) {
            pixels[ source.width * j + i ] = source.data [ source.height * i + (source.width - 1 - j )];
        }
    }

    return some_image(source.height, source.width, pixels);

}

static struct image rotate_0_degrees( const struct image source, struct pixel *pixels ) {

    for (size_t i = 0; i < source.height * source.width; ++i) {
        pixels[ i ] = source.data [ i ];
    }

    return some_image(source.width, source.height, pixels);

}

struct image rotate(const struct image source, const uint16_t degrees ) {

    if (source.data == NULL) {
        return some_image(source.height, source.width, NULL);
    }

    struct pixel *pixels = malloc(sizeof(struct pixel) * source.width * source.height);

    switch (degrees) {

        case 90:  return rotate_90_degrees(source, pixels);
        case 180: return rotate_180_degrees(source, pixels);
        case 270: return rotate_270_degrees(source, pixels);
        default: return rotate_0_degrees(source, pixels);

    }


}
