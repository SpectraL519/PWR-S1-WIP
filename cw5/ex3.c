#include <stdio.h>
#include "declarations2-5.h"



void delete (List *ptr, int i) {
    List prev = NULL;
    List curr = *ptr;
    while (curr != NULL) {
        if (curr->value != i) {
            prev = curr;
            curr = curr->next;
        }
        else {
            if (prev == NULL) {
                List tmp = curr->next;
                free(curr);
                curr = tmp;
                *ptr = curr;
            }
            else {
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        }
    }
}
