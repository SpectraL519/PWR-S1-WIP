#include <stdio.h>
#include <math.h>



int sigma (int x) {
    int sum = 0;
    for (int i = 1; i < x; i++) {
        if (x % i == 0) sum += i;
    }
    return sum;
}



int main()
{
    int Sigma [1001];

    printf("Perfect numbers smaller than 1000:\n");
    for (int i = 1; i < 1000; i++) {
        Sigma[i] = sigma(i);
        if (Sigma[i] == i)  
            printf("%d\n", i);
    }

    printf("\nAmicable numbers smaller than 1000:\n");
    for (int i = 1; i < 999; i++)
        if (Sigma[i] <= 1000 && Sigma[i] > i)
            if (Sigma[Sigma[i]] == i)
                printf("%d %d\n", i, Sigma[i]);

    return 0;
}
