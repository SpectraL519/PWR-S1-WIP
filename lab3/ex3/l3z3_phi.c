#include "functions.h"
#include <math.h>



int phi (long int n) {
	if (prime(n))
		return n-1;
	else {
		int Phi = 1;
		int p = 2;
		while (n > 1) {
			if (n % p == 0) {
				int k = 0;
				while (n % p == 0) {
					k++;
					n /= p;
				}
				Phi *= (pow(p,k-1)) * (p-1);
			}
			p++;
		}

		return Phi;
	}
}