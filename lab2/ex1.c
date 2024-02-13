#include <stdio.h>



int pln, pennies, notes[9], count, ind;



void Init() {
    count = 0;
    ind = 8;
    notes[0] = 1;
    notes[1] = 2;
    notes[2] = 5;
    notes[3] = 10;
    notes[4] = 20;
    notes[5] = 50;
    notes[6] = 100;
    notes[7] = 200;
    notes[8] = 500;

    pennies += ((pln % 10) * 100);
    pln -= (pln % 10);
}



void Data() {
    printf("Enter PLN: ");
    scanf("%d", &pln);
    printf("Enter pennies: ");
    scanf("%d", &pennies);
}



int main() {
    Data();
    Init();

    if (pln >= 10) {
        printf("Notes:\n");
        while (pln >= 10) {
            while (pln >= notes[ind]) {
                pln -= notes[ind];
                count++;
            }
            if (count != 0)
                printf("  %d x %dpln\n", count,notes[ind]);
            count = 0;
            ind--;
        }
    }
    
    ind = 8;
    if (pennies > 0) {
        printf("Coins:\n");
        while (pennies > 0) {
            while (pennies >= notes[ind]) {
                pennies -= notes[ind];
                count++;
            }
            if (count != 0) {
                if (notes[ind] >= 100)
                    printf("  %d x %dpln\n", count,(notes[ind]/100));
                else
                    printf("  %d x %dpennies\n", count,notes[ind]);
            }
            count = 0;
            ind--;
        }
    }

    return 0;
}
