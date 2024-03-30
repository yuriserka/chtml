#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#include "tags/html.h"

int main() {
  Html *html = html_create(
    "my portfolio",
    style_create(
      list_of(3,
        style_pair_create(STYLE_TYPE_BACKGROUND_COLOR, "rgba(0, 0, 0, 0.1)"),
        style_pair_create(STYLE_TYPE_COLOR, "white"),
        style_pair_create(STYLE_TYPE_MARGIN, "1.2rem")
      )
    ),
    div_create(
      style_create(
        list_of(1,
          style_pair_create(STYLE_TYPE_BACKGROUND_COLOR, "rgba(0, 0, 255, 0.3)")
        )
      ),
      list_of(3,
        span_create(
          "hello world",
          style_create(
            list_of(1, style_pair_create(STYLE_TYPE_PADDING, "1rem"))
          )
        ),
        img_create("https://picsum.photos/500/500", "alt text", 500, 500),
        div_create(
          style_create(
            list_of(1,
              style_pair_create(STYLE_TYPE_BACKGROUND_COLOR, "rgba(0, 255, 0, 0.3)")
            )
          ),
          list_of(3,
            span_create("hello world 2", NULL),
            img_create("https://picsum.photos/300/300", "alt text", 300, 300),
            anchor_create(
              "https://www.linkedin.com/in/yuriserka/",
              style_create(
                list_of(2,
                  style_pair_create(STYLE_TYPE_COLOR, "blue"),
                  style_pair_create(STYLE_TYPE_PADDING, "2rem")
                )
              ),
              list_of(2,
                span_create("linkedin", NULL),
                img_create("https://i.pinimg.com/236x/f3/85/d7/f385d78eba93e8b768bcc04bf96fe5a5.jpg", "profile", 500, 500)
              )
            )
          )
        )
      )
    )
  );
  html_print(html);
  html_destroy(html);
  return 0;
}
