
#include "image/image.h"

#include "inputs/bmp_io.h"

#include "inputs/file_open_close.h"

#include "transformations/90rotate.h"

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Некорректный ввод\n");
        return 0;
    }

    FILE* file;

    file_open(argv[1], &file, "r");

    struct image img = {0};

    from_bmp(file, &img);
    file_close(file);

    struct image res = rotate(img, 90);

    FILE* res_file;

    file_open(argv[2], &res_file, "w");

    to_bmp(res_file, &res);
    file_close(res_file);

    image_destroy(&img);
    image_destroy(&res);

    return 0;

}

