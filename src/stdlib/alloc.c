#include <p-clib.h>
#include <stdlib.h>
#include <string.h>

/* * * * * * * * * * * * * * * * *
 * Portland libc stdlib/alloc.c  *
 * Copyright 2018 Benji Dial     *
 * Under GNU GPL v3.0            *
 * * * * * * * * * * * * * * * * */

static struct alloc {
  void *ptr;
  size_t size;
  struct alloc *prev;
} *next_alloc {
  .prev = NULL;
};

static size_t next_allocation = 0;

void *calloc(size_t nmemb, size_t size) {
  size_t bytes = next_alloc->size = nmemb * size;
  int *r = (int *)(next_alloc->ptr = mem_alloc(bytes));
  size_t tmp = bytes >> 2;
  while (tmp)
    r[--tmp] = 0;
  tmp = bytes & 3;
  bytes &= ~3;
  while (tmp)
    ((char *)r)[bytes + --tmp] = 0;
  struct alloc *tmp2 = next_alloc;
  (next_alloc = (struct alloc *)mem_alloc(sizeof(struct alloc)))->prev = tmp2;
  return (void *)r;
}

void free(void *ptr) {
  if (ptr) {
    mem_free(ptr);
    struct alloc *tmp = next_alloc;
    while (tmp->prev->ptr != ptr)
      tmp = tmp->prev;
    void *tmp2 = (void *)(tmp->prev);
    tmp->prev = tmp->prev->prev;
    mem_free(tmp2);
  }
}

void *realloc(void *ptr, size_t size) {
  if (ptr) {
    void *new = malloc(size);
    struct alloc *tmp = next_alloc;
    while (tmp->prev->ptr != ptr)
      tmp = tmp->prev;
    memcpy(tmp->prev->ptr, new, size > tmp->prev->size ? tmp->prev->size : size);
    mem_free((void *)(tmp->prev->ptr));
    struct alloc *tmp2 = tmp->prev->prev;
    mem_free((void *)(tmp->prev));
    tmp->prev = tmp2;
    return new;
  } else
    return malloc(size);
}

void *malloc(size_t size) {
  void *ret = next_alloc->ptr = mem_alloc(next_alloc->size = size);
  struct alloc *tmp = next_alloc;
  next_alloc = mem_alloc(sizeof(struct alloc));
  next_alloc->prev = tmp;
  return ret;
}
