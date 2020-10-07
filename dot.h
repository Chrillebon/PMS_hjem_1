#include <stdio.h>
#include <stdlib.h>

#ifndef DOT_H
#define DOT_H

double dot(double * row1, double * row2, unsigned int k) {

    double total;

    for (size_t i = 0; i < k; i++)
    {
        total += row1[i] * row2[i];
    }
    return total;
}

#endif