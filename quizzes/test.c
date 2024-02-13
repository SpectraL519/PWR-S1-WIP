#include <stdio.h>
#include <stdbool.h>



bool _if (int *ptr)
{
    int *curr = ptr;
    if (curr != NULL)
        return true;
    return false;
}



int main() {
    int *ptr;
    ptr = 3;
    if (_if(ptr))
        printf("%d\n",ptr);
    else 
        printf("NULL\n");

    return 0;
}