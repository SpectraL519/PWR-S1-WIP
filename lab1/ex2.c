#include <stdio.h>
#include <math.h>



int main() {
    double a, b, c, delta;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a == 0.0)
        printf("The equation isn't quadratic!\n");
    else {
        delta = ((b*b) - (4*a*c));
        if (delta > 0.0)
            printf("x1 = %lf\nx2 = %lf\n", ((-b - sqrt(delta))/(2*a)), ((-b + sqrt(delta))/(2*a)));
            //x0 = ((-b +- sqrt(delta))/(2*a))
        else if (delta == 0.0)
            printf("x0 = %lf\n", ((-b)/(2*a)));
        else
            printf("The quadratic equation of given coeeficients has no solutions in the set of real numbers!");
    }

    return 0;
}
