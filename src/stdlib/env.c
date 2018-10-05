#include <p-clib.h>
#include <stdlib.h>

/* * * * * * * * * * * * * * * *
 * Portland libc stdlib/env.c  *
 * Copyright 2018 Benji Dial   *
 * Under GNU GPL v3.0          *
 * * * * * * * * * * * * * * * */

static struct func_block {
  void (*funcs[32])(void);
  size_t n_funcs = 0;
  struct func_block *prev;
} *last_func_block = malloc(sizeof(struct func_block));

void abort(void) {
  /*TODO*/
}

int atexit(void (*func)(void)) {
  if (last_func_block->n_func == 32) {
    struct func_block *tmp = last;
    if (last = malloc(sizeof(struct func_block))) {
      last->prev = tmp;
      last->n_funcs = 1;
      last->funcs[0] = func;
      return 0;
    }
    last = tmp;
    return 1;
  }
  last->funcs[last->n_funcs++] = func;
  return 0;
}

/*FIXME: cannot handle registered functions registering more functions*/
void exit(int status) {
  struct func_block *tmp = last;
  do {
    size_t i = tmp->n_funcs;
    while (i--)
      tmp->funcs[i]();
  } while (tmp = tmp->prev);
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
