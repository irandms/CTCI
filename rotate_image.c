#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define IMG_HEIGHT 4
#define IMG_WIDTH 4

typedef struct {
    uint8_t red;
    uint8_t blue;
    uint8_t green;
    uint8_t alpha;
} pixel;


typedef struct {
    pixel **pixels;
    int width;
    int height;
} image;

void print_image(image *img) {
    int i, j;

    pixel **pxs = img->pixels;

    for(i = 0; i < IMG_WIDTH; i++) {
        for(j = 0; j < IMG_HEIGHT; j++) {
            printf("%d,%d ", pxs[i][j].red, pxs[i][j].blue);
        }
        puts("");
    }
    puts("Image fully printed.");
}

image *rotate_image(image *img) {
    int i, j;
    image *ret = malloc(sizeof(image));
    ret->height = img->height;
    ret->width = img->width;

    ret->pixels = malloc(sizeof(pixel *) * img->width);
    for(i = 0; i < img->height; i++) {
        ret->pixels[i] = malloc(sizeof(pixel));
    }

    for(i = 0; i < img->width; i++) {
        for(j = 0; j < img->height; j++) {
            ret->pixels[i][j].red = img->pixels[img->width - j-1][i].red;
            ret->pixels[i][j].blue = img->pixels[img->width - j-1][i].blue;
            ret->pixels[i][j].green = img->pixels[img->width - j-1][i].green;
            ret->pixels[i][j].alpha = img->pixels[img->width - j-1][i].alpha;
        }
    }

    return ret;
}

image *make_img(int height, int width) {
    int i;
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    
    img->pixels = malloc(sizeof(pixel *) * width);
    for(i = 0; i < height; i++) {
        img->pixels[i] = malloc(sizeof(pixel));
    }
    
    return img;
}

int main() {
    int i, j;
    image *my_img = make_img(IMG_HEIGHT, IMG_WIDTH);

    for(i = 0; i < IMG_WIDTH; i++) {
        for(j = 0; j < IMG_HEIGHT; j++) {
            my_img->pixels[i][j].red = i;
            my_img->pixels[i][j].blue = j;
            my_img->pixels[i][j].green = 0;
            my_img->pixels[i][j].alpha = 0;
        }
    }

    print_image(my_img);

    image *rotated_my_img = rotate_image(my_img);

    print_image(rotated_my_img);
}
