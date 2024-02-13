#include <stdio.h>
#include <math.h>

int main() {
    int n = 1;
    double sum = 1.0;

    while (sum <= 10) {
        n++;
        sum += pow(n,(-1));
    }

    printf("The smallest natural number which satisfies the equation is n = %d\n", n);

    return 0;
}