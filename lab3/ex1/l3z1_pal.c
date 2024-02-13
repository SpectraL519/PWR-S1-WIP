#include <stdbool.h>
#include <string.h>
#include "functions.h"



bool palindrome (char text[])
{
    int l = strlen(text);
    for (int i = 0; i < l/2; i++)
        if (text[i] != text[l-1-i])     
            return false;

    return true;
}