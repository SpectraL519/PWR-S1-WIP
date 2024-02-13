#include <stdio.h>

/*
int f (int m, int n) // recursicve
{
    if(n == 0 || m == n)
        return 1;
    
    return (m * f(m - 1, n - 1)) / n;
}



int f (int m, int n, int nominator, int denominator) // tail recursive
{
    if (n == 0 || n == m)
        return nominator / denominator;
    
    return (f(m - 1,n - 1,m * nominator,n * denominator));
}
*/

int f (int m, int n)
{
    if (n == 0 || n == m)
        return 1;
    
    int nominator = 1, denominator = 1;
    while (n != 0)
    {
        nominator *= m;
        denominator *= n;
        m--;
        n--;
    }
    return nominator / denominator;
}

int main()
{
    int n, m;
    printf("Enter n: ");
    scanf("%d",&n);
    printf("Enter m: ");
    scanf("%d",&m);
    printf("f(m,n) = %d\n",f(m,n)); // recursive, iterative
    // printf("f(m,n) = %d\n",f(m,n,1,1)); // tail recursive

    return 0;
}
