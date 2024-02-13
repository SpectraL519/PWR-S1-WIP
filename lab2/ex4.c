#include <stdio.h>
#include <math.h>



int main()
{
    double root = 1, factorial = 1;
    for (int i = 1; i <= 1000; i++) {
        root *= pow(i, (1.0/1000.0));
    }
    printf("The 1000th root of 1000! is qpproximately %lf\n", root);

    return 0;
}
