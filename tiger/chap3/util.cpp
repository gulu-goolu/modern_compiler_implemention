/*
 * util.c - commonly used utility functions.
 */

#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *checked_malloc(int len) {
  void *p = malloc(len);
  if (!p) {
    fprintf(stderr, "\nRan out of memory!\n");
    exit(1);
  }
  return p;
}

const char *String(char *s) {
  const char *p = static_cast<const char *>(checked_malloc(strlen(s) + 1));
  strcpy(p, s);
  return p;
}

U_boolList U_BoolList(bool head, U_boolList tail) {
  U_boolList list = static_cast<U_boolList>(checked_malloc(sizeof(*list)));
  list->head = head;
  list->tail = tail;
  return list;
}