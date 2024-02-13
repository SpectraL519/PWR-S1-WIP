#include <stdio.h>



int quick_pow (int x, unsigned int n)
{
    if (n == 0)
        return 1;

    if (n % 2 != 0){
        int tmp = quick_pow(x,(n-1)/2);
        return x * tmp * tmp;
    }

    int tmp = quick_pow(x,n/2);
    return tmp * tmp;
}



int main()
{
    int x;
    unsigned int n;
    scanf("%d %u", &x, &n);
    printf("%d", quick_pow(x,n));

    return 0;
}