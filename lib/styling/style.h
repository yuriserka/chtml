#pragma once

#include "list/list.h"

typedef enum style_type_t {
  STYLE_TYPE_PADDING,
  STYLE_TYPE_MARGIN,
  STYLE_TYPE_COLOR,
  STYLE_TYPE_BACKGROUND_COLOR,
  STYLE_TYPE_CURSOR,
} StyleType;

typedef struct style_pair_t {
  StyleType prop;
  char *value;
} StylePair;

typedef struct style_t {
  List *values;
} Style;

Style *style_create(List *values);
StylePair *style_pair_create(StyleType prop, char *value);
void style_destroy(Style *style);
char *style_string(Style *style);
