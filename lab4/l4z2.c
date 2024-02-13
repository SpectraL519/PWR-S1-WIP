/*
There is an error in this code which I cannot find,
so I've rewritten the entire game in C++ :) (in the cpp_mastermind directory)
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>



void Init(int **codeList) {
    int set_colors[4] = {1,1,1,1};
    for (int i = 0; i < 1296; i++) {
        for (int j = 0; j < 4; j++)
            codeList[i][j] = set_colors[j];

        int k = 3;
        set_colors[k]++;
        while (set_colors[k] > 6) {
            set_colors[k] = 1;
            if (k - 1 >= 0) {
                k--;
                set_colors[k]++;
            }
        }
    }
}



void assignValue (int *A, int *B)  {
    for (int i = 0; i < 4; i++)
        A[i] = B[i];
}



void test(int *codeGuess, int *red, int *white) {
    int x, y; // red, white
    for (int i = 0; i < 4; i++)
        printf("[%d] ", codeGuess[i]);
    printf("?\n");
    printf("red: ");
    scanf("%d", &x);
    printf("white: ");
    scanf("%d", &y);
    printf("\n");
    *red = x;
    *white = y;
}



int redKey (int *code, int *guess) {
    int red = 0;
    for (int i = 0; i < 4; i++) // checking whether guess has the same elements and on the same positions as code
        if (guess[i] == code[i]) {
            red++;
            guess[i] = -1; // flag: don't check this element in the next iteration (same positions)
            code[i] = -2; // flag: don't check this element in the next iteration (different positions)
        }

    return red;
}



int whiteKey(int *code, int *guess) {
    int white = 0;
    for (int i = 0; i < 4; i++) // checking whether guess has the same elements but on different positions as code
        if (guess[i] != -1)
            for (int j = 0; j < 4; j++)
                if (guess[i] == code[j]) {
                    white++;
                    code[j] = -2; // flag: don't check this element in the next iteration (different positions)
                    break;
                }

    return white;
}



void Mastermind()
{
    int **codeList; // 6^4 = 1296 color combination
    codeList = (int **)malloc(1296 * sizeof(int *)); // memory allocation for the codeList array
    assert(codeList != NULL);
    for (int i = 0; i < 1296; i++) {
        codeList[i] = (int *)malloc(4 * sizeof(int));
        assert(codeList[i] != NULL);
    }

    Init(codeList); // fill the codeList array with all possible combinations
    int possible = 1296; // initial number of possible codes

    int codeGuess[4];
    int red, white;

    for (int g = 1; g <= 8; g++) { // game loop - max 8 rounds
        if (possible != 0) {
            int p = rand() % possible; // generate random code
            possible--;
            assignValue(codeGuess,codeList[p]);
            for (int i = p; i < possible - 1; i++) // delete p-th element from codeList
                assignValue(codeList[i], codeList[i+1]);

            printf("Round %d\n",g);
            test(codeGuess, &red, &white); // code testing: get values of white and red
            if (red < 0 || white < 0 || red > 4 || white > 4 || red + white > 4 || (red == 3 && white == 1) || (red == 4 && white != 0)) {
                printf("You are dumb!\n");
                break;
            }
            else if (red == 4) {
                printf("I win!\n");
                printf("Your code was: ");
                for (int i = 0; i < 4; i++)
                    printf("[%d] ",codeGuess[i]);
                printf("\n");
                break;
            }
            else if (possible == 0 || g == 8) {
                printf("You are cheating!\n");
                break;
            }
            else {
                int guessCopy[4]; // codeGuess copy
                int codeBreaker[4]; // codeList[i] copy
                int r, w; // red and white code for codeBreaker
                int position = 0; // next correct code position

                for (int n = 0; n < possible; n++)
                {
                    assignValue(codeBreaker,codeList[n]);
                    assignValue(guessCopy,codeGuess);
                    // get the red and white key to check the guess against the code
                    r = redKey(guessCopy,codeBreaker);
                    w = whiteKey(guessCopy,codeBreaker);

                    if (r == red && w == white) {
                        assignValue(codeList[position], codeList[n]); // insert a correct code into the codeList array at `position`
                        position++;
                    }
                }
                possible = position; // `position` correct codes have been selected
            }
        }
        else {
            printf("You are cheating!\n");
            break;
        }
    }

    for (int i = 0; i < 1296; i++)
        free(codeList[i]);
    free(codeList);
}



int main()
{
    printf("Welcome to Mastermin!\n");
    printf("If you want to play, enter START, otherwise enter STOP\n");
    char game[6];
    scanf("%s",game);
    strupr(game);
    if (!strcmp(game,"START"))
    {
        printf("\nWell...let's get rollin'\n\n");
        Mastermind();
        printf("\nThank you for the game!\nI hope you will come to play with me again soon!\n");
    }
    else
        printf("\nIt's a pity you didn't want to play with me!\nMaby next time!\n");


    return 0;
}
