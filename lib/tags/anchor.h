#pragma once

typedef struct anchor_t Anchor;

#include "list/list.h"
#include "tags/tag.h"

struct anchor_t {
  char *key;
  char* href;
  List* children;
  Style* style;
};

Tag* anchor_create(char* href, Style *style, List* children);
void anchor_destroy(Anchor* anchor);
void anchor_print(Anchor* anchor, int indent);
