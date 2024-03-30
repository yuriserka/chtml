#pragma once

typedef struct div_t Div;

#include "list/list.h"
#include "tag.h"

struct div_t {
  char *key;
  List *children;
  Style *style;
};

Tag *div_create(Style *style, List *children);
void div_destroy(Div *div);
void div_print(Div *div, int indent);