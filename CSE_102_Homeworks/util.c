#include <stdio.h>
#include "util.h"

void fraction_print(int numerator, int denominator) {
    printf("%d//%d", numerator, denominator);
}  /* end fraction_print */

void fraction_add(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 + n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_add */

void fraction_sub(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2 - n2*d1;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_sub */

void fraction_mul(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*n2;
    *d3 = d1*d2;
    fraction_simplify(n3, d3);
} /* end fraction_mul */

void fraction_div(int n1, int d1, int n2, int d2, int * n3, int * d3) {
    *n3 = n1*d2;
    *d3 = n2*d1;
    fraction_simplify(n3, d3);
} /* end fraction_div */

/* Simplify the given fraction such that they are divided by their GCD */
void fraction_simplify(int * n, int * d) {
    int gcd = 1;
    /* takes both numbers absolute values with elvis operator */
    int num = *n < 0 ? -(*n) : *n;
    int den = *d < 0 ? -(*d) : *d;
    
    // loop for find the GCD 
    for (int i = 1; i <= num && i <= den ; i++) {
        if (num % i == 0 && den % i == 0) {
            gcd = i;
        }
    }
    
    // divide both numbers gcd for simplification
    *n /= gcd;
    *d /= gcd;
    
    /* check if both numbers are negative, and if so, make them positive again */
    if (*d < 0 && *n < 0) {
        *n = -(*n);
        *d = -(*d);
    }
} /* end fraction_div */
