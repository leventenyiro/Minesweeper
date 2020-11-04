#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// paraméterek átvétele 0 terminál stringgel vannak elválasztva
// char* argv[] karakterek tömbjére mutató pointer

void initTable(int table[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            table[i][j] = 0;
        }
    }
}

void placeMine(int minePiece, int table[10][10]) {
    time_t t;
    srand((unsigned)time(&t));
    for (int i = 0; i < minePiece; i++) {
        int row = 0, column = 0;
        do {
            row = rand() % 10;
            column = rand() % 10;
            if (table[row][column] == 0) {
                table[row][column] = -1;
            }
        } while (table[row][column] == 0);
    }
}

void placeNumbers(int table[10][10]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (table[i][j] != -1) {
                int sum = 0;
                int leftBorder = j - 1, rightBorder = j + 1, topBorder = i - 1, bottomBorder = i + 1;
                if (i == 0)
                    topBorder = 0;
                else if (i == 10)
                    bottomBorder = 10;
                else if (j == 0)
                    leftBorder = 0;
                else if (j == 10)
                    rightBorder = 10;

                for (int k = topBorder; k <= bottomBorder; k++) {
                    for (int l = leftBorder; l <= rightBorder; l++) {
                        if (table[k][l] == -1)
                            sum++;
                    }
                }
                table[i][j] = sum;
            }
        }
    }
}

void show(int found[10][10]) {
    for (int i = 0; i < 10; ++i) {
        printf("\t%d", i);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%c", 65 + i);
        for (int j = 0; j < 10; ++j) {
            printf("\tX");
        }
        printf("\n");
    }
}

void solution(int table[10][10]) {
    for (int i = 0; i < 10; ++i) {
        printf("\t%d", i);
    }
    printf("\n");
    for (int i = 0; i < 10; ++i) {
        printf("%c", 65 + i);
        for (int j = 0; j < 10; ++j) {
            printf("\t%d", table[i][j]);
        }
    printf("\n");
    }
}

int main() {

    int table[10][10];
    initTable(table);
    //printf("%d\n", table[0][0]);

    int found[10][10];
    int minePiece;
    do {
        printf("Aknak szama: ");
        scanf("%d", &minePiece);
        if (minePiece < 3 || minePiece > 30)
            printf("Az aknak szama nem lehet kisebb, mint 3 es nagyobb, mint 30!\n");
    } while (minePiece < 3 || minePiece > 30);

    placeMine(minePiece, table);
    placeNumbers(table);

    char tip[255];
    do {
        // bekérés

        do {
            printf("Tipp (pl.: A9): ");
            scanf("%s[^\n]", tip);
            if (tip[0] < 'A' || tip[0] > 'J' || tip[1] < '0' || tip[1] > '9')
                printf("A tipp A-J es 0-9 kozott mozog!");
        } while (tip[0] < 'A' || tip[0] > 'J' || tip[1] < '0' || tip[1] > '9');

    } while ()


    show(found);

    //solution(table); - megoldás

    return 0;
}
