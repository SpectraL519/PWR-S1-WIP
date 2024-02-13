#include <stdlib.h>
#include <assert.h>
#include "declarations6-11.h"



void delete_tree (Tree *ptr) {
    Tree curr = *ptr;
    Tree tmp;

    while (*ptr != NULL) {
        assert(curr != NULL);
        if (curr->left != NULL)
            curr = curr->left;
        else {
            curr->left = (*ptr)->right;
            tmp = (*ptr)->left;
            if (curr == *ptr)
                curr = curr->left;
            free(*ptr);
            *ptr = tmp;
        }
    }

    // free(*ptr) - czy necessary?
}