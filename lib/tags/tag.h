#pragma once

typedef enum tag_type_t {
  TAG_TYPE_DIV,
  TAG_TYPE_IMAGE,
  TAG_TYPE_SPAN,
  TAG_TYPE_ANCHOR
} TagType;
typedef struct tag_t Tag;

#include <stdarg.h>

#include "list/node.h"
#include "styling/style.h"
#include "tags/anchor.h"
#include "tags/div.h"
#include "tags/img.h"
#include "tags/span.h"

typedef struct tag_node_value_t {
  Div *div;
  Image *image;
  Span *span;
  Anchor *anchor;
} TagNodeValue;

typedef struct tag_t {
  char *key;
  TagType type;
  TagNodeValue value;
} Tag;

Tag *tag_create(TagType type, char *key, int n_args, ...);
void tag_destroy(Tag *tag);
void tag_print(Tag *tag, const int indent);
