#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void *xmalloc (size_t n) {
  void *ret = malloc (n);
  if (!ret && n) {
    fprintf (stderr, "out of memory\n");
    exit (EXIT_FAILURE);
  }
  return ret;
}
