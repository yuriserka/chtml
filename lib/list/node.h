#pragma once

typedef struct list_node_t {
  void* data;
  struct list_node_t* next;
  struct list_node_t* prev;
} ListNode;

ListNode* list_node_create(void* data);
