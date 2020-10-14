#include <stdlib.h>
#include <math.h>

double dot(double * row, double ** matrix, int k) {
    // dot product with column k in matrix and vector
    double total = 0;

    for (int i = 0; i < k; i++)
    {
        total += row[i] * matrix[i][k];
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
      b[i] = (b[i] - dot(b, R, i)) / denom;
    }
    return 0;
  }
