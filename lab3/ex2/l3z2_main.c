#include <stdio.h>
#include <assert.h>
#include <math.h>
#include "functions.h"



int main() {
    int k;
    double a, b;
    printf("Data:\n\tf(x) = cos(x/2)\n\ta = ");
    scanf("%lf", &a);
    printf("\tb = ");
    scanf("%lf", &b);
    assert(a < b);
    assert(f(a) * f(b) < 0);
    printf("\tepsilon = 10^(-k), k = ");
    scanf("%d", &k);
    printf("Solutiuon:\n\tf(x) = 0 in range [%lf,%lf] for x = %lf\n", a, b, solution(a, b, pow(0.1, k)));

    return 0;
}