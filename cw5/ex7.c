#include <stdlib.h>
#include "declarations6-11.h"



int leaf_no (Tree ptr) {
    if (ptr == NULL)
        return 0;
    
    if (ptr->left == NULL && ptr->right == NULL)
        return 1;

    return leaf_no(ptr->left) + leaf_no(ptr->right);
}