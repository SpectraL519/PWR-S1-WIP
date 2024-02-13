#include <stdlib.h>
#include "declarations6-11.h"



void delete_tree (Tree *ptr) {
    Tree curr;

    while (*ptr != NULL) { // O(n^2) complexity
        curr = *ptr;
        while (curr->left != NULL || curr->right != NULL) {
            if (curr->left != NULL)
                curr = curr->left;
            else
                curr = curr->left;
        }
        
        free(curr->left);
        free(curr->right);
        curr = NULL;
    }

    // free(*ptr) - necessary?
}
