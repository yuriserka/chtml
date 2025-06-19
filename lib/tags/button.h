#pragma once

typedef struct button_t Button;

#include "tags/tag.h"

struct button_t {
  char *key;
  char *text;
  Style *style;
};

Tag *button_create(char *text, Style *style);
void button_destroy(Button *button);
void button_print(Button *button, int indent);