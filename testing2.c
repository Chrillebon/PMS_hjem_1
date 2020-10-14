#include "forward_substitution.h"
#include "array_alloc.h"
#include "printing_reading.h"
#include <stdlib.h>

int main()
{
  int returnval;
  int n;
  double alpha;
  double **A;
  double *b, *x;
  // creating array testing:
  FILE *test, *svar;
  test = fopen("testcases2.txt", "r"); // r for read
  svar = fopen("answers2.txt", "r");

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

    matrixread(test, A, n);

    vectorread(test, b, n);
    vectorread(svar, x, n);

    // HER SKAL VI INDSÆTTE "fwdsub()", SÅ VI OPDATERER B
    returnval = fwdsub(n, alpha, A, b);

    if(returnval == -1)
    {
      printf("we have had a problem!!!\n");
    }


    if(eqtest(b, x, n, 1e-10))
    {
      printf("Succes!\n");
    }
    else
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

  // tester hvis man sender nullpointers ind:
  returnval = fwdsub(2, -1, NULL, NULL);
  if(returnval == -1)
  {
    printf("good return brah\n");
  }

  fclose(test);
  fclose(svar);
  return 0;
}
