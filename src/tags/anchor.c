#include "tags/anchor.h"

#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

Tag *anchor_create(char *href, Style *style, List *children) {
  Anchor *anchor = calloc(1, sizeof(Anchor));
  anchor->href = href;
  anchor->children = children;
  anchor->style = style;
  anchor->key = uuid4_create();
  return tag_create(TAG_TYPE_ANCHOR, anchor->key, 1, anchor);
}

void anchor_destroy(Anchor *anchor) {
  if (anchor == NULL) {
    return;
  }
  if (anchor->style != NULL) {
    style_destroy(anchor->style);
  }
  if (anchor->children != NULL) {
    list_destroy(anchor->children, { tag_destroy(__IT__->data); });
    free(anchor->children);
  }
  free(anchor);
}

void anchor_print(Anchor *anchor, int indent) {
  if (anchor == NULL) {
    return;
  }

  char *style = style_string(anchor->style);
  printf("%*s<a id=\"%s\" href=\"%s\" style=\"%s\">\n", indent * 4, "",
         anchor->key, anchor->href, style);
  free(style);
  if (anchor->children != NULL) {
    LIST_FOR_EACH(anchor->children, { tag_print(__IT__->data, indent + 1); });
  }
  printf("%*s</a>\n", indent * 4, "");
}