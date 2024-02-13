#include <stdio.h>
#include <stdlib.h>



struct Node {
    int value;
    struct Wezel *next;
};



// iterative
int sum (struct Note *ptr) {
    int result = 0;
    struct Node *curr = ptr;
    while (curr != NULL)
    {
        result += curr->value;
        curr = curr->next;
    }

    return result;
}


// recursive
/*
int sum (struct Node *ptr) {
    if (ptr != NULL)
        return wsptrk->value + sum(ptr->next);
    
    return 0;
}
*/