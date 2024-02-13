#include <stdio.h>
#include <assert.h>



int a (int n) {
    if (n == 0)
        return 0;

    return 2 * n - 1 + a(n - 1);
}



int main() {
    int n;
    printf("Enter n: ");
    scanf("%d",&n);
    assert(n >= 0);
    printf("nth element in the `a` sequence: %d\n",a(n));

    return 0;
}

// proof - induction over n