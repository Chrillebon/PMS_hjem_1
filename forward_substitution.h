#include <stdlib.h>
#include <math.h>
#include "dot.h"

int eqtest(double * a, double * b, unsigned int n, double epsilon) {
  for (size_t i = 0; i < n; i++)
  {
    printf("first element: %lf   Second element: %lf\n", a[i], b[i]);
    if (abs(a[i] - b[i]) > epsilon)
    {
      return 0;
    }
  }
  return 1;  
}

int fwdsub(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){
    for (size_t i = 0; i < n; i++)
    {
      b[i] = (b[i] - dot(b, R[i], i)) / (alpha + R[i][i]);
    }
  }
