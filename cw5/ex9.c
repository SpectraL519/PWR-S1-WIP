#include <stdlib.h>
#include "declarations6-11.h"



void delete_tree (Tree *ptr)
{
    if (*ptr != NULL) {
        delete_tree(&((*ptr)->left));
        delete_tree(&((*ptr)->right));
        free(*ptr);
        *ptr = NULL;
    }
}