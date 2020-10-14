#ifndef MATRIXPRINT_H
#define MATRIXPRINT_H
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
#endif


#ifndef VECTORPRINT_H
#define VECTORPRINT_H
void vectorprint(int n, double* vector)
{
  for(int i=0;i<n;i++)
  {
    printf("%lf ", vector[i]);
  }
  printf("\n");
  return;
}
#endif


#ifndef MATRIXREAD_H
#define MATRIXREAD_H

void matrixread(FILE * source, double ** A, int n)
{
  for(int i=0;i<n;i++)
  {
    for(int o=0;o<n;o++)
    {
      fscanf(source, "%lf", &A[i][o]);
    }
  }
  return;
}
#endif


#ifndef VECTORREAD_H
#define VECTORREAD_H

void vectorread(FILE * source, double * v, int n)
{
  for(int i=0;i<n;i++)
  {
    fscanf(source, "%lf", &v[i]);
  }
  return;
}
#endif
