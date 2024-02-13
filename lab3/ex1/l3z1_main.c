#include <stdio.h>
#include <string.h>
#include "functions.h"



int main() {
    char text[100];
    printf("Enter string: ");
    scanf("%s", text);

    if (palindrome(text))
        printf("Given string is a palindrome!\n");
    else
        printf("Given string is NOT a palindrome!\n");

    return 0;
}