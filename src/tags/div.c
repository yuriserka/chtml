#include "tags/div.h"

#include <stdio.h>
#include <stdlib.h>

#include "list/list.h"
#include "uuid4/uuid4.h"

Tag *div_create(Style *style, List *children) {
  Div *div = calloc(1, sizeof(Div));
  div->children = children;
  div->style = style;
  div->key = uuid4_create();
  return tag_create(TAG_TYPE_DIV, div->key, 1, div);
}

void div_destroy(Div *div) {
  if (div == NULL) {
    return;
  }
  if (div->style != NULL) {
    style_destroy(div->style);
  }
  if (div->children != NULL) {
    list_destroy(div->children, { tag_destroy(__IT__->data); });
    free(div->children);
  }
  free(div);
}

void div_print(Div *div, int indent) {
  if (div == NULL) {
    return;
  }

  char *style = style_string(div->style);
  printf("%*s<div id=\"%s\" style=\"%s\">\n", indent * 4, "", div->key, style);
  free(style);
  if (div->children != NULL) {
    LIST_FOR_EACH(div->children, { tag_print(__IT__->data, indent + 1); });
  }
  printf("%*s</div>\n", indent * 4, "");
}