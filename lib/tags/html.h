#pragma once

#include <tags/tag.h>

typedef struct html_t {
  char *title;
  Tag *body;
  Style *style;
} Html;

Html *html_create(char *title, Style *style, Tag *body);
void html_destroy(Html *html);
void html_print(Html *html);
