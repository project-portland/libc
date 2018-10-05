#include <stdlib.h>

/* * * * * * * * * * * * * * * *
 * Portland libc stdlib/prng.c *
 * Copyright 2018 Benji Dial   *
 * Under GNU GPL v3.0          *
 * * * * * * * * * * * * * * * */

static unsigned int rand_seed = 1;

int rand(void) {
  /*TODO: permute rand_seed*/
  return rand_seed & RAND_MAX;
}

void srand(unsigned int seed) {
  rand_seed = seed;
}
