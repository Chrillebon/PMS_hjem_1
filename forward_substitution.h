#include <stdlib.h>
#include <math.h>

double sumcalc(double * row, double ** matrix, int k) {
    // dot product with column k in matrix and vector
    double total = 0.0, c = 0.0, t, y;

    for (int i = 0; i < k; i++)
    {
      y = row[i] * matrix[i][k] - c;
      t = total + y;
      c = (t - total) - y;
      total = t;
    }
    return total;
}

int fwdsub(
  unsigned long n,
  double alpha,
  double **R,  /* two-dimensional array, row-major */
  double *b    /* one-dimensional array */
  ){
    if(R == NULL)
    {
      return -1;
    }
    if(R[0] == NULL || b == NULL)
    {
      return -1;
    }
    double denom;
    for (size_t i = 0; i < n; i++)
    {
      denom = alpha + R[i][i];
      if(denom == 0)
      {
        return -1;
      }
      b[i] = (b[i] - sumcalc(b, R, i)) / denom;
    }
    return 0;
  }
