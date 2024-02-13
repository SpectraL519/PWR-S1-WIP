#include <stdlib.h>
#include "declarations6-11.h"



int nodes_no (Tree ptr) {
    if (ptr == NULL)
        return 0;
    
    return 1 + nodes_no(ptr->left) + nodes_no(ptr->right);
}

