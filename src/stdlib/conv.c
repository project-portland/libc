#include <stdbool.h>
#include <stdlib.h>

/* * * * * * * * * * * * * * * *
 * Portland libc stdlib/conv.c *
 * Copyright 2018 Benji Dial   *
 * Under GNU GPL v3.0          *
 * * * * * * * * * * * * * * * */

double atof(const char *nptr) {
  /*TODO*/
}

int atoi(const char *nptr) {
  bool neg = *nptr == '-';
  int val = 0;
  size_t i = neg - 1;
  while ((nptr[++i] | 0x07) == 0x37 || nptr[i] == 0x39) {
    val *= 10;
    val += nptr[i] - 0x30;
  }
  return neg ? -val : val;
}

long int atol(const char *nptr) {
  bool neg = *nptr == '-';
  long int val = 0;
  size_t i = neg - 1;
  while ((nptr[++i] | 0x07) == 0x37 || nptr[i] == 0x39) {
    val *= 10;
    val += nptr[i] - 0x30;
  }
  return neg ? -val : val;
}

long long atoi(const char *nptr) {
  bool neg = *nptr == '-';
  long long int val = 0;
  size_t i = neg - 1;
  while ((nptr[++i] | 0x07) == 0x37 || nptr[i] == 0x39) {
    val *= 10;
    val += nptr[i] - 0x30;
  }
  return neg ? -val : val;
}

double strtod(const char *nptr, char **endptr) {
  /*TODO*/
}

float strtof(const char *nptr, char **endptr) {
  /*TODO*/
}

long double strtold(const char *nptr, char **endptr) {
  /*TODO*/
}

long int strtol(const char *nptr, char **endptr, int base) {
  /*TODO*/
}

long long int strtoll(const char *nptr, char **endptr, int base) {
  /*TODO*/
}

unsigned long int strtoul(const char *nptr, char **endptr, int base) {
  /*TODO*/
}

unsigned long long int strtoull(const char *nptr, char **endptr, int base) {
  /*TODO*/
}
