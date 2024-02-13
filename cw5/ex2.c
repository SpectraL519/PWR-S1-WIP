#include <stdio.h>
#include "declarations2-5.h"



void add_nondecreasing (List *ptr, int i) {
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->value = i;
    List curr = *ptr;
    List prev = NULL;
    while (curr != NULL && i > curr->value)
    {
        prev = curr;
        curr = curr->next;
    }
    newNode->next = curr;
    if (prev != NULL)
        prev->next = newNode;
    else    
        *ptr = newNode;
}
