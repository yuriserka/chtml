#include "tags/button.h"

#include <stdio.h>
#include <stdlib.h>

#include "uuid4/uuid4.h"

Tag *button_create(char *text, Style *style) {
  Button *button = calloc(1, sizeof(Button));
  button->text = text;
  button->style = style;
  button->key = uuid4_create();

  return tag_create(TAG_TYPE_BUTTON, button->key, 1, button);
}

void button_destroy(Button *button) {
  if (button == NULL) {
    return;
  }
  style_destroy(button->style);
  free(button);
}

void button_print(Button *button, int indent) {
  if (button == NULL) {
    return;
  }

  list_push_back(button->style->values,
                 style_pair_create(STYLE_TYPE_CURSOR, "pointer"));

  char *style = style_string(button->style);
  printf("%*s<button id=\"%s\" style=\"%s\">%s</button>\n", indent * 4, "",
         button->key, style, button->text);
  free(style);
}