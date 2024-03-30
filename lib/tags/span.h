#pragma once

typedef struct span_t Span;

#include "tags/tag.h"

struct span_t {
  char *key;
  char* content;
  Style* style;
};

Tag* span_create(char* text, Style *style);
void span_destroy(Span* span);
void span_print(Span* span, int indent);