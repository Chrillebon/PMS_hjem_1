#include "forward_substitution.h"
#include "array_alloc.h"
#include "printing.h"


int main()
{
  int n;
  double alpha;
  double **A;
  double *b, *x;
  // creating array testing:
  FILE *test, *svar;
  test = fopen("testcases.txt", "r"); // r for read
  svar = fopen("answers.txt", "r");

  while(1)
  {
    fscanf(test, "%d", &n);
    if(n == -1) // testcases slutter med -1
    {
      break;
    }
    fscanf(test, "%lf", &alpha);

    A = make2Dspace(n,n);
    b = make1Dspace(n);
    x = make1Dspace(n);
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
      fscanf(svar, "%lf", &x[i]);
    }
    
    // HER SKAL VI INDSÆTTE "fwdsub()", SÅ VI OPDATERER B
    fwdsub(n, alpha, A, b);
    if (eqtest(b, x, n, 1e-10))
    {
      printf("Succes!\n");
    } else
    {
      printf("Error go home fool!\n");
    }
    
    
    

    // HER SKAL VI INDSÆTTE "equal()", SÅ VI TJEKKER AT VI HAR KORREKT SVAR
    // PRINTER STATUS PÅ FUNKTIONEN:

    // for printing:
    /*printf("Har taget et array og gemt det.\nHer er A:\n");
    matrixprint(n, A);
    printf("samt b som er:\n");
    vectorprint(n, b);*/
    free2Dspace(A);
    free(b);
    b = NULL;
    free(x);
    x == NULL;
  }

  fclose(test);
  fclose(svar);
  return 0;
}
