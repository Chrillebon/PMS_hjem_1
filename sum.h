#include <stdio.h>
#include <stdlib.h>

#ifndef SUM_H
#define SUM_H

double sum(double * row, unsigned int k) {

    double total;

    for (size_t i = 0; i < k; i++)
    {
        total += row[i];
    }
    return total;
}



#endif