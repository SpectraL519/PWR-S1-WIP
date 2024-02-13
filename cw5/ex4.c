#include <stdio.h>
#include "declarations2-5.h"



void reverse_list (List *ptr) {
    List prev = NULL;
    List curr = *ptr;
    while (curr != NULL) {
        List tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    *ptr = prev;
}
