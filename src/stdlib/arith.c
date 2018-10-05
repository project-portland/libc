#include <stdlib.h>

/* * * * * * * * * * * * * * * * *
 * Portland libc stdlib/arith.c  *
 * Copyright 2018 Benji Dial     *
 * Under GNU GPL v3.0            *
 * * * * * * * * * * * * * * * * */

int abs(int j) {
  return (j & 0x80000000) ? ~j + 1 : j;
}

long int labs(long int j) {
  /*TODO*/
}

long long int llabs(long int j) {
  /*TODO*/
}

div_t div(int numer, int denom) {
  div_t r {
    .q = numer / denom;
    .r = numer % denom;
  };
  return r;
}

ldiv_t ldiv(long int numer, long int denom) {
  ldiv_t r {
    .q = numer / denom;
    .r = numer % denom;
  };
  return r;
}

lldiv_t lldiv(long long int numer, long long int denom) {
  lldiv_t r {
    .q = numer / denom;
    .r = numer % denom;
  };
  return r;
}
