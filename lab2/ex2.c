#include <stdio.h>
#include <assert.h>



int main() {
    int n;
    double x, avg = 0;
    printf("Enter n: ");
    scanf("%d", &n);
    assert(n > 0);
    printf("Enter %d real numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &x);
        avg += x;
    }
    avg /= n;
    printf("%lf\n", avg);

    return 0;
}
