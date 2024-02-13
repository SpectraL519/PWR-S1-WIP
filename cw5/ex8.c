#include <stdlib.h>
#include "declarations6-11.h"



int max (int a, int b) {
    if (a >= b)
        return a;
    
    return b;
}



int height (Tree ptr) {
    if (ptr == NULL)
        return 0;

    return 1 + max(height(ptr->left), height(ptr->right));
}