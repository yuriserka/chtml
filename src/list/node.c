#include "list/node.h"

#include <stdlib.h>

ListNode *list_node_create(void *value) {
  ListNode *node = calloc(1, sizeof(ListNode));
  node->data = value;
  node->next = NULL;
  node->prev = NULL;
  return node;
}
