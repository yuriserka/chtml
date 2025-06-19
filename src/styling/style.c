#include "styling/style.h"

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Style *style_create(List *values) {
  Style *style = calloc(1, sizeof(Style));
  style->values = values;
  return style;
}

void style_destroy(Style *style) {
  if (style == NULL) {
    return;
  }
  list_destroy(style->values, { free(__IT__->data); });
  free(style);
}

StylePair *style_pair_create(StyleType prop, char *value) {
  StylePair *pair = calloc(1, sizeof(StylePair));
  pair->prop = prop;
  pair->value = value;
  return pair;
}

char *style_string(Style *style) {
  char *str = calloc(1024, sizeof(char));

  if (style == NULL) {
    return str;
  }

  list_for_each(style->values, {
    StylePair *pair = __IT__->data;
    char *prop = NULL;
    switch (pair->prop) {
      case STYLE_TYPE_PADDING:
        prop = "padding";
        break;
      case STYLE_TYPE_MARGIN:
        prop = "margin";
        break;
      case STYLE_TYPE_COLOR:
        prop = "color";
        break;
      case STYLE_TYPE_BACKGROUND_COLOR:
        prop = "background-color";
        break;
      case STYLE_TYPE_CURSOR:
        prop = "cursor";
        break;
    }
    char *temp = calloc(strlen(prop) + strlen(pair->value) + 10, sizeof(char));
    sprintf(temp, "%s: %s; ", prop, pair->value);
    strcat(str, temp);
    free(temp);
  });

  return str;
}