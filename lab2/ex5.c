#include <stdio.h>
#include <math.h>



int GCD (int a, int b) {
    int tmp;

    while (b != 0) {
        tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}



int main() {
    int tau = 1;

    printf("n; tau(n)/n^2\n");

    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j < i; j++) {
            if (GCD(i,j) == 1) // i > j
                tau += 2;
        }

        printf("%d;%lf\n", i, (double)(tau / pow(i,2)));
    }

    return 0;
}