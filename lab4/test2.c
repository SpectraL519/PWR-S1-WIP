#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



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



void test(int *testCode, int *codeGuess, int *red, int *white) {
    int guessCopy[4]; 
    int codeBreaker[4]; 
    assignValue(codeBreaker,testCode);
    assignValue(guessCopy,codeGuess);
    int r = redKey(guessCopy,codeBreaker);
    int w = whiteKey(guessCopy,codeBreaker);

    *red = r;
    *white = w;
}



int Mastermind (int *testCode, int *rounds, double *avg) {
    int **codeList; 
    codeList = (int **)malloc(1296 * sizeof(int *)); 
    assert(codeList != NULL);
    for (int i = 0; i < 1296; i++)
    {
        codeList[i] = (int *)malloc(4 * sizeof(int));
        assert(codeList[i] != NULL);
    }

    Init(codeList); 
    int possible = 1296; 

    int codeGuess[4]; 
    int red, white;
    
    for (int g = 1; g <= 8; g++)
    {
        if (possible != 0)
        {
            int p = rand() % possible; 
            possible--;
            assignValue(codeGuess,codeList[p]);
            for (int i = p; i < possible - 1; i++)
                assignValue(codeList[i],codeList[i+1]);

            test(testCode, codeGuess, &red, &white); 
            if (red < 0 || white < 0 || red > 4 || white > 4 || red + white > 4 || (red == 3 && white == 1) || (red == 4 && white != 0))
                return -1;
            else if (red == 4)
            {  
                rounds[g]++;
                *avg += g;
                return 1;
            }
            else if (possible == 0 || g == 8)
                return 0;
            else
            {
                int guessCopy[4]; 
                int codeBreaker[4]; 
                int r, w; 
                int position = 0; 
                for (int n = 0; n < possible; n++)
                {
                    assignValue(codeBreaker,codeList[n]);
                    assignValue(guessCopy,codeGuess);
                    r = redKey(guessCopy,codeBreaker);
                    w = whiteKey(guessCopy,codeBreaker);

                    if (r == red && w == white)
                    {
                        assignValue(codeList[position],codeList[n]);
                        position++;
                    }
                }
                possible = position;
            }
        }
        else
            return -1;
    }

    for (int i = 0; i < 1296; i++)
        free(codeList[i]);
    free(codeList);

    return -2;
}



int main() {
    int **testList; 
    testList = (int **)malloc(1296 * sizeof(int *)); 
    assert(testList != NULL);
    for (int i = 0; i < 1296; i++) {
        testList[i] = (int *)malloc(4 * sizeof(int));
        assert(testList[i] != NULL);
    }
    Init(testList);

    int done = 0; // mm = 1
    int rounds[10] = {0};
    double avg = 0.0;
    int cheater = 0; // mm = 0
    int dumb = 0; // mm = -1
    int error = 0; // mm = -2

    printf("Wrong codes:\n");
    
    for (int t = 0; t < 1296; t++) {
        int mm = Mastermind(testList[t],rounds,&avg);
        if (mm == 1)
            done++;
        else if (mm == 0) {
            cheater++;
            for (int i = 0; i < 4; i++)
                printf("%d",testList[t][i]);
            printf("\n");
        }
        else if (mm == -1) {
            dumb++;
            for (int i = 0; i < 4; i++)
                printf("%d",testList[t][i]);
            printf("\n");
        }
        else if (mm == -2) {
            error++;
            for (int i = 0; i < 4; i++)
                printf("%d",testList[t][i]);
            printf("\n");
        }
    }
    avg /= done;

    printf("\nTest outcome: \n");
    printf("\tdone = %d\n",done);
    printf("\tavg = %lf\n",avg);
    printf("\tCodes guessed in n rounds:\n");
    for (int i = 1; i <= 8; i++)
        printf("\t\t%d: %d\n",i,rounds[i]);
    printf("\tcheater = %d\n",cheater);
    printf("\tdumb = %d\n",dumb);
    printf("\terror = %d\n",error);

    for (int i = 0; i < 1296; i++)
        free(testList[i]);
    free(testList);

    return 0;
}