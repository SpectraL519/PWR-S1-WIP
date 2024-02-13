#include <stdio.h>

/*
int f (int n) // recursive
{
    if (n == 0)
        return 0;
    
    return n + f(n-1);
}



int f (int n, int sigma) // tail recursive
{
    if (n == 0)
        return sigma;
        
    return f(n - 1, n + sigma);
}
*/



int f (int n) {
    int sigma = 0;
    while (n != 0) {
        sigma += n;
        n--;
    }
    return sigma;
}


int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("f(n) = %d\n",f(n)); // recursive, iterative
    // printf("f(n) = %d\n",f(n,0)); // tail recursive

    return 0;
}