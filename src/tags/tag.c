#include "tags/tag.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

#define TAG_INIT_UNION(__VA_LIST__, __MEM__, __T__) \
  (TagNodeValue) { .__MEM__ = va_arg(__VA_LIST__, __T__ *) }

Tag *tag_create(TagType type, char *key, int n_args, ...) {
  Tag *tag = calloc(1, sizeof(Tag));

  tag->key = key;
  tag->type = type;

  va_list args;
  va_start(args, n_args);

  switch (type) {
    case TAG_TYPE_DIV:
      tag->value = TAG_INIT_UNION(args, div, Div);
      break;
    case TAG_TYPE_IMAGE:
      tag->value = TAG_INIT_UNION(args, image, Image);
      break;
    case TAG_TYPE_SPAN:
      tag->value = TAG_INIT_UNION(args, span, Span);
      break;
    case TAG_TYPE_ANCHOR:
      tag->value = TAG_INIT_UNION(args, anchor, Anchor);
      break;
    case TAG_TYPE_BUTTON:
      tag->value = TAG_INIT_UNION(args, button, Button);
      break;
  }

  va_end(args);

  return tag;
}

void tag_destroy(Tag *tag) {
  if (tag == NULL) {
    return;
  }

  free(tag->key);

  switch (tag->type) {
    case TAG_TYPE_DIV:
      div_destroy(tag->value.div);
      break;
    case TAG_TYPE_IMAGE:
      img_destroy(tag->value.image);
      break;
    case TAG_TYPE_SPAN:
      span_destroy(tag->value.span);
      break;
    case TAG_TYPE_ANCHOR:
      anchor_destroy(tag->value.anchor);
      break;
    case TAG_TYPE_BUTTON:
      button_destroy(tag->value.button);
      break;
  }

  free(tag);
}

void tag_print(Tag *tag, const int indent) {
  if (tag == NULL) {
    return;
  }

  switch (tag->type) {
    case TAG_TYPE_DIV:
      div_print(tag->value.div, indent);
      break;
    case TAG_TYPE_IMAGE:
      img_print(tag->value.image, indent);
      break;
    case TAG_TYPE_SPAN:
      span_print(tag->value.span, indent);
      break;
    case TAG_TYPE_ANCHOR:
      anchor_print(tag->value.anchor, indent);
      break;
    case TAG_TYPE_BUTTON:
      button_print(tag->value.button, indent);
      break;
  }
}
