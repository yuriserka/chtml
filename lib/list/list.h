#pragma once

#include <stddef.h>

#include "list/node.h"

typedef struct list_t {
  ListNode* head;
  ListNode* tail;
  size_t size;
} List;

List* list_create();
List* list_of(size_t size, ...);
void list_push_back(List* list, void* data);

#define list_fill(__TARGET__, __T__, __N_ARGS__, ...)              \
  {                                                                \
    va_list __VA_LIST__;                                           \
    va_start(__VA_LIST__, __N_ARGS__);                             \
    for (int __INDEX__ = 0; __INDEX__ < __N_ARGS__; ++__INDEX__) { \
      __T__ __CASTED_VAR_ARG_AS_T = va_arg(__VA_LIST__, __T__);    \
      list_push_back(__TARGET__, __CASTED_VAR_ARG_AS_T);           \
    }                                                              \
    va_end(__VA_LIST__);                                           \
  }

#define list_for_each(__LIST__, __CALLBACK__) \
  {                                           \
    if (__LIST__ != NULL) {                   \
      ListNode* __IT__ = __LIST__->head;      \
      unsigned int __INDEX__ = 0;             \
      while (__IT__) {                        \
        ListNode* __IT_NXT__ = __IT__->next;  \
        __CALLBACK__;                         \
        __IT__ = __IT_NXT__;                  \
        ++__INDEX__;                          \
      }                                       \
    }                                         \
  }

#define list_destroy(__LIST__, __CALLBACK__) \
  {                                          \
    if (__LIST__ != NULL) {                  \
      ListNode* __IT__ = __LIST__->head;     \
      unsigned int __INDEX__ = 0;            \
      while (__IT__) {                       \
        ListNode* __IT_NXT__ = __IT__->next; \
        __CALLBACK__;                        \
        free(__IT__);                        \
        ++__INDEX__;                         \
        __IT__ = __IT_NXT__;                 \
      }                                      \
      free(__LIST__);                        \
    }                                        \
  }
