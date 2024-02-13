#include <stdio.h>



/* recursion
int f (int n, int p) {
    if (n == 0)
        return 1;
    else
        return p * f(n - 1, p + 1);
}
*/



// tail recursion
int f (int n, int p, int accumulator) {
    if (n == 0)
        return accumulator;
    else
        return f(n - 1, p + 1, p * accumulator);
}



/* iterative
int f (int n, int p) {
    int accumulator = 1;
    while (n != 0) {
        accumulator *= p;
        p++;
        n--;
    }
    return accumulator;
}
*/



int main()
{
    int n, p;
    printf("Podaj n: ");
    scanf("%d",&n);
    printf("Podaj p: ");
    scanf("%d",&p);
    //printf("f(%d,%d) = %d\n",n,p,f(n,p)); // wywolanie f w postaci pierwotnej i iteracyjnej
    printf("f(%d,%d) = %d\n",n,p,f(n,p,1)); // wywolanie f w postaci ogonowej

    return 0;
}