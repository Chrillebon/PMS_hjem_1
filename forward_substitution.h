#include <stdlib.h>
#include <math.h>
#include "dot.h"

int fwdsub(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){
    for (size_t i = 0; i < n; i++)
    {
      b[i] -= dot(b, R[i], i) / (alpha + R[i][i]);
    }
  }
