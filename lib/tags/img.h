#pragma once

typedef struct img_t Image;

#include "tag.h"

struct img_t {
  char *key;
  char *src;
  char *alt;
  int width;
  int height;
};

Tag *img_create(char *src, char *alt, int width, int height);
void img_destroy(Image *img);
void img_print(Image *img, int indent);