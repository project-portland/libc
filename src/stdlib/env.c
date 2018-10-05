#include <p-clib.h>
#include <stdlib.h>

/* * * * * * * * * * * * * * * *
 * Portland libc stdlib/env.c  *
 * Copyright 2018 Benji Dial   *
 * Under GNU GPL v3.0          *
 * * * * * * * * * * * * * * * */

static struct func_block {
  void (*funcs[32])(void);
  size_t n_funcs;
  struct func_block *prev;
} *last_func_block = NULL;

void abort(void) {
  /*TODO*/
}

int atexit(void (*func)(void)) {
  if (last_func_block == NULL) {
    if (last_func_block = malloc(sizeof(struct func_block))) {
      last_funck_block->prev = NULL;
      last_funck_block->n_funcs = 1;
      last_funck_block->func[0] = func;
      return 0;
    }
    return 1;
  } if (last_func_block->n_func == 32) {
    struct func_block *tmp = last_func_block;
    if (last_funck_block = malloc(sizeof(struct func_block))) {
      last_funck_block->prev = tmp;
      last_funck_block->n_funcs = 1;
      last_funck_block->funcs[0] = func;
      return 0;
    }
    last_funck_block = tmp;
    return 1;
  }
  last_funck_block->funcs[last_funck_block->n_funcs++] = func;
  return 0;
}

void exit(int status) {
  while (last_func_block) {
    struct func_block *tmp = last_func_block;
    last_func_block = NULL;
    do {
      size_t i = tmp->n_funcs;
      while (i--)
        tmp->funcs[i]();
    } while (tmp = tmp->prev);
  }
  _Exit(status);
}

void _Exit(int status) {
  /*TODO: cleanup*/
  /*TODO: exit program*/
}

char *getenv(const char *name) {
  /*TODO*/
}

int system(const char *string) {
  if (*string) {
    int r;
    file_exec(string, &r);
    return r;
  }
  return 1;
}
