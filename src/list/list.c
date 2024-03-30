#include "list/list.h"

#include <stdarg.h>
#include <stdlib.h>

List *list_create() {
  List *list = calloc(1, sizeof(List));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

List *list_of(size_t size, ...) {
  List *list = list_create();
  list_fill(list, void *, size);
  return list;
}

void list_push_back(List *list, void *data) {
  ListNode *node = list_node_create(data);

  if (list->size == 0) {
    list->head = node;
    list->tail = node;
  } else {
    list->tail->next = node;
    list->tail = node;
  }

  ++list->size;
}
