#include <stdbool.h>
#include <math.h>



bool prime (long int n) {
    long int p = sqrt(n);
    for (int i = 2; i <= p; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}