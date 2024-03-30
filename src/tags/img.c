#include "tags/img.h"

#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

Tag *img_create(char *src, char *alt, int width, int height) {
  Image *img = calloc(1, sizeof(Image));
  img->src = src;
  img->alt = alt;
  img->width = width;
  img->height = height;
  return tag_create(TAG_TYPE_IMAGE, uuid4_create(), 1, img);
}

void img_destroy(Image *img) {
  if (img == NULL) {
    return;
  }
  free(img);
}

void img_print(Image *img, int indent) {
  if (img == NULL) {
    return;
  }

  printf("%*s<img src=\"%s\" alt=\"%s\" width=\"%d\" height=\"%d\" />\n",
         indent * 4, "", img->src, img->alt, img->width, img->height);
}