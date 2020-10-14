#include <stdlib.h>
#include <math.h>
#include "matrix.h"

double sumcalc(double * row, double ** matrix, int k) {
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
      return -2;
    }
    if(R[0] == NULL || b == NULL)
    {
      return -2;
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


int tri_sylvester_solve(const matrix_t *R, matrix_t *C) {
  // Tjekker for nullpointers
  if(R == NULL || C == NULL)
  {
    return -2;
  }
  if(R->A == NULL || C->A == NULL)
  {
    return -2;
  }
  if(R->m != R->n || R->n <= 0 || C->m != C->n || C->n <= 0 || R->n != C->n)
  {
    return -2;
  }
  if(R->A[0] == NULL || C->A[0] == NULL)
  {
    return -2;
  }

  // part 1:
  int n = R->n, returnval;

  // Column i transponerede er row i alm.
  for(int k=0; k<n; k++) // hver række
  {
    for(int i=0; i<n; i++) // hvert index i række
    {
      for(int j=0; j<k; j++) // alle værdier i colonne over dette index
      {
        // alle index i hver række
        C->A[k][i] -= C->A[j][i] * R->A[j][k];
      }
    }

    // part 2:

    returnval = fwdsub(n, R->A[k][k], R->A, C->A[k]);
    if(returnval == -2)
    {
      return -2;
    }
    else if(returnval == -1)
    {
      return -1;
    }
  }
  return 0;
}
