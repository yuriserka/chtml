#include "tags/span.h"

#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

Tag *span_create(char *text, Style *style) {
  Span *span = calloc(1, sizeof(Span));
  span->content = text;
  span->style = style;
  span->key = uuid4_create();
  return tag_create(TAG_TYPE_SPAN, span->key, 1, span);
}

void span_destroy(Span *span) {
  if (span == NULL) {
    return;
  }
  style_destroy(span->style);
  free(span);
}

void span_print(Span *span, int indent) {
  if (span == NULL) {
    return;
  }

  char *style = style_string(span->style);
  printf("%*s<span id=\"%s\" style=\"%s\">%s</span>\n", indent * 4, "",
         span->key, style, span->content);
  free(style);
}