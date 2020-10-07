#include "forward_substitution.h"
#include "array_alloc.h"

void matrixprint(int n, double** matrix)
{
  for(int i=0;i<n;i++)
  {
    for(int o=0;o<n;o++)
    {
      printf("%lf ", matrix[i][o]);
    }
    printf("\n");
  }
  return;
}

void vectorprint(int n, double* vector)
{
  for(int i=0;i<n;i++)
  {
    printf("%lf ", vector[i]);
  }
  printf("\n");
  return;
}


int main()
{
  int n;
  double **A;
  double *b;
  // creating array testing:
  FILE *test;
  test = fopen("testcases.txt", "r"); // r for read
  int pullval;
  //fscanf(test, "%d", &pullval);
  //printf("pulling first value: %d\n", pullval);

  while(1)
  {
    fscanf(test, "%d", &n);
    A = make2Dspace(n,n);
    for(int i=0;i<n;i++)
    {
      for(int o=0;o<n;o++)
      {
        fscanf(test, "%lf", &A[i][o]);
      }
    }
    for(int i=0;i<n;i++)
    {
      fscanf(test, "%lf", &b[i]);
    }
    printf("Har taget et array og gemt det.\nHer er A:\n");
    matrixprint(n, A);
    printf("samt b som er:\n");
    vectorprint(n, b);
    free2Dspace(A);
    break; // bare her i starten
  }

  fclose(test);
  /*double **matrix;
  matrix = make2Dspace(3,4);
  matrix[0][0] = 1;
  matrix[0][1] = 2;
  matrix[0][2] = 3;
  printf("Testing that array alloc works: %.0lf%.0lf%.0lf\n", matrix[0][0], matrix[0][1], matrix[0][2]);
  free2Dspace(matrix);
  if(matrix == NULL)
  {
    printf("actually freeing memory!\n");
  }*/
  return 0;
}
