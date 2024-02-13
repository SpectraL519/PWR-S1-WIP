#include "functions.h"

double solution (double a, double b, double eps) {
    double x;
    while ((b - a) > /*2**/eps) {
        x = (a + b) / 2;
        if (f(x) == 0)
            return x;
        else if ((f(a) * f(x)) < 0)
            b = x;
        else if ((f(x) * f(b)) < 0)
            a = x;
    }
    x = (a + b) / 2;

    return x;
}