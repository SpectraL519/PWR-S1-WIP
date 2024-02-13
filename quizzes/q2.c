#include <stdio.h>



int main()  {
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    double t[n];
    printf("Enter t array: ");
    for (int i = 0; i < 10; i++)
        scanf("%lf",&t[i]);

       
    /* Give code:
    int licznik = 0;
    i = 1;
    while (i < n-1)
    {
        while (i < n-1 && t[i] <= t[i-1])
            i = i+1;
        if (i < n-1 && t[i] > t[i+1])
            licznik = licznik + 1;
    }
    printf("Liczba maksimow lokalnych = %d\n",liczba);
    */


    // Correct code:
    int licznik = 0;
    int i = 1;
    while (i < n-1) {
        while (i < n-1 && t[i] <= t[i - 1])
            i = i+1;
        if (i < n-1 && t[i] > t[i + 1]) {
            licznik = licznik + 1;
        }
        i = i+1;
    }
    printf("Liczba maksimow lokalnych = %d\n",licznik);


    return 0;
}