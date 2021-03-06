#include <stdio.h>
#include <stdlib.h>

#ifndef MAKE2DSPACE_H
#define MAKE2DSPACE_H

// Gøre klar til plads for matrix
double** make2Dspace(int m, int n)
{
  // liste af lister (pointer til pointers)
  double **matrix;
  // Laver plads til "m" lister (pointers) af type double
  matrix = (double **)malloc(m*sizeof(double*));

  // Hvis der er allokeringsfejl
  if(matrix == NULL)
  {
    return NULL;
  }

  // Allokerer alt pladsen til alle elementer
  // Dette gøres på første plads (smarte hop
  // til andre steder i matricen kommer lige
  // om lidt)
  matrix[0] = (double *)malloc(m*n*sizeof(double));
  // igen, hvis der er problemer med allokering
  if(matrix[0] == NULL)
  {
    free(matrix);
    return NULL;
  }

  // Her laver vi alle de smarte hop som gør
  // at vi hurtigt kan komme til den række i
  // matricen som vi vil.
  // Hvis man altså hopper til matrix[2][4]
  // hopper man 2*n+4 ind i matricen
  // Får "første-koordinaten" til at virke
  for(int i=1; i<m; i++)
  {
    // "res[0] + i*n" betyder at vi skal have
    // en pointer til det sted i memory som
    // ligger i*n "længere henne" end dér hvor
    // matrix[0] peger hen.
    matrix[i] = matrix[0] + i*n;
  }

  return matrix;
}
#endif


// Samme for anden kommando
#ifndef FREE2DSPACE_H
#define FREE2DSPACE_H
void free2Dspace(double** matrix)
{
  // Rydder op efter os
  // Starter med at fjerne alle m*n værdier
  // som er "gemt på matrix[0]"
  free(matrix[0]);
  matrix[0] = NULL;

  // Fjerner vores hop til forskellige steder
  // i vores m*n matrix
  free(matrix);
  matrix = NULL;
  return;
}
#endif

#ifndef MAKE1DSPACE_H
#define MAKE1DSPACE_H
double* make1Dspace(int n)
{
  double * vector;
  // Laver plads til n doubles
  vector = (double *)malloc(n*sizeof(double));
  // Hvis der er allokeringsfejl
  if(vector == NULL)
  {
    return NULL;
  }
  return vector;
}

#endif
