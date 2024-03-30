#include "tags/html.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Html *html_create(char *title, Style *style, Tag *body) {
  Html *html = calloc(1, sizeof(Html));
  html->title = title;
  html->style = style;
  html->body = body;
  return html;
}

void html_destroy(Html *html) {
  if (html == NULL) {
    return;
  }
  style_destroy(html->style);
  tag_destroy(html->body);
  free(html);
}

void html_print(Html *html) {
  printf("<!DOCTYPE html>\n");
  printf("<html lang=\"en\">\n");
  printf("<head>\n");
  printf("\t<meta charset=\"UTF-8\">\n");
  printf(
      "\t<meta name=\"viewport\" content=\"width=device-width, "
      "initial-scale=1.0\">\n");
  printf("\t<title>%s</title>\n", html->title);
  printf("</head>\n");

  char *style_str = style_string(html->style);
  printf("<body style=\"%s\">\n", style_str);
  free(style_str);

  tag_print(html->body, 0);

  printf("</body>\n");
  printf("</html>\n");
}