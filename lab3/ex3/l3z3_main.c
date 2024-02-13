#include <stdio.h>
#include <assert.h>
#include "functions.h"



int main() {
	long int n;
	printf("Enter n: ");
	scanf("%ld", &n);
	assert(n > 0);
	printf("phi(%ld) = %d\n", n, phi(n));

	return 0;
}