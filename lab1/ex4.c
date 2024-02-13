#include <stdio.h>



int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n - i - 1); j++) // in the ith row there is supposed to be (n-i-1) spaces before the astrix characters
            printf(" ");
        for (int j = 0; j < (((i+1)*2)-1); j++) // in the ith row there is supposed to be (((i+1)*2)-1) astrix characters
            printf("*");
        printf("\n");
    }

    return 0;
}
