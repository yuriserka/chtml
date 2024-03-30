#include "tags/tag.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

#define TAG_INIT_UNION(MEM, TGT) \
  (TagNodeValue) { .MEM = va_arg(ptr, TGT *) }

Tag *tag_create(TagType type, char *key, int n_args, ...) {
  Tag *tag = calloc(1, sizeof(Tag));

  tag->key = key;
  tag->type = type;

  va_list ptr;
  va_start(ptr, n_args);

  switch (type) {
    case TAG_TYPE_DIV:
      tag->value = TAG_INIT_UNION(div, Div);
      break;
    case TAG_TYPE_IMAGE:
      tag->value = TAG_INIT_UNION(image, Image);
      break;
    case TAG_TYPE_SPAN:
      tag->value = TAG_INIT_UNION(span, Span);
      break;
    case TAG_TYPE_ANCHOR:
      tag->value = TAG_INIT_UNION(anchor, Anchor);
      break;
  }

  va_end(ptr);

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
  }
}
