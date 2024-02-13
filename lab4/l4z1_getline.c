#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



bool match (char *pattern, char *string) {
    int lp = strlen(pattern);
    int ls = strlen(string);
    int p = 0; // current position in the string

    if (lp * ls == 0 && lp == ls)
        return true;
    else {
        if (pattern[0] == '*') {
            while (p <= ls) {
                if (match(pattern + 1,string + p))
                    return true;
                p++;
            }
            return false;
        }
        else if (pattern[0] == '?' || pattern[0] == string[0])
            return match(pattern + 1,string + 1);
        else
            return false;
    }

    return false;
}



void readArray (char *array, size_t size) {
    getline(&array , &size, stdin);
    int length = strlen(array);
    for (int i = 0; i < length; i++) {
        while (array[i] == ' ' || array[i] == '\t') {
            length--;
            for (int j = i; j < length; j++)
                array[j] = array[j + 1];
        }
    }
    array[length-1] = '\0';
}



int main() {
    char *pattern, *string;
    int size = 100;

    pattern = (char *)malloc(size * sizeof(char));
    string = (char *)malloc(size * sizeof(char));

    printf("Enter pattern: ");
    readArray(pattern, size);
    printf("Enter string: ");
    readArray(string, size);

    if (match(pattern, string))
        printf("String matches the pattern!\n");
    else
        printf("String doesn't match the pattern!\n");

    free(pattern);
    free(string);

    return 0;
}