// NOMBRE - RICARDO SANTIAGO CABRERA
// crea un cuadrado magico de cualquier dimension positiva usando apuntadores
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int MAX;
    printf("Ingrese la dimension del cuadrado: ");
    scanf_s("%d", &MAX);

    if (MAX <= 0) {
        printf("El tamano debe ser un numero positivo.\n");
        return 1;
    }

    int** matriz = (int**)malloc(MAX * sizeof(int*));
    for (int i = 0; i < MAX; i++) {
        *(matriz + i) = (int*)calloc(MAX, sizeof(int));
    }

    int cntdr = 0;
    int ren, col;
    int aren, acol;

    if (MAX % 2 != 0) {
        ren = 0; col = MAX / 2;
        for (cntdr = 1; cntdr <= MAX * MAX; cntdr++)
        {
            *(*(matriz + ren) + col) = cntdr;
            aren = ren; acol = col;
            ren--;
            col++;
            if (ren < 0)
                ren = MAX - 1;
            if (col >= MAX)
                col = 0;
            if (*(*(matriz + ren) + col) != 0)
            {
                ren = aren + 1;
                col = acol;
            }
        }
    }
    else if (MAX % 4 == 0) {
        int num = 1;
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                int en_zona = (i % 4 == j % 4) || ((i % 4 + j % 4) == 3);
                if (en_zona) {
                    *(*(matriz + i) + j) = num;
                }
                else {
                    *(*(matriz + i) + j) = (MAX * MAX + 1) - num;
                }
                num++;
            }
        }
    }
    else {
        int n = MAX;
        int halfN = n / 2;
        int subSize = halfN * halfN;
        int** sub = (int**)malloc(halfN * sizeof(int*));
        for (int i = 0; i < halfN; i++) {
            *(sub + i) = (int*)calloc(halfN, sizeof(int));
        }

        int r = 0, c = halfN / 2;
        for (int k = 1; k <= subSize; k++) {
            *(*(sub + r) + c) = k;
            int ar = r, ac = c;
            r--; c++;
            if (r < 0) r = halfN - 1;
            if (c >= halfN) c = 0;
            if (*(*(sub + r) + c) != 0) {
                r = ar + 1;
                c = ac;
            }
        }

        for (int i = 0; i < halfN; i++) {
            for (int j = 0; j < halfN; j++) {
                int val = *(*(sub + i) + j) - 1;
                int bi = 2 * i, bj = 2 * j;
                char tipo;
                if (i < halfN / 2) tipo = 'L';
                else if (i == halfN / 2 && j == halfN / 2) tipo = 'U';
                else if (i == halfN / 2 + 1 && j == halfN / 2) tipo = 'L';
                else if (i == halfN / 2) tipo = 'X';
                else tipo = 'X';

                if (i == halfN / 2 && j == halfN / 2 - 1) tipo = 'U';
                else if (i == halfN / 2 + 1 && j == halfN / 2 - 1) tipo = 'X';

                int base = 4 * val;
                if (tipo == 'L') {
                    *(*(matriz + bi) + bj) = base + 4;
                    *(*(matriz + bi + 1) + bj) = base + 1;
                    *(*(matriz + bi + 1) + bj + 1) = base + 2;
                    *(*(matriz + bi) + bj + 1) = base + 3;
                }
                else if (tipo == 'U') {
                    *(*(matriz + bi) + bj) = base + 1;
                    *(*(matriz + bi + 1) + bj) = base + 4;
                    *(*(matriz + bi + 1) + bj + 1) = base + 2;
                    *(*(matriz + bi) + bj + 1) = base + 3;
                }
                else {
                    *(*(matriz + bi) + bj) = base + 1;
                    *(*(matriz + bi + 1) + bj) = base + 4;
                    *(*(matriz + bi + 1) + bj + 1) = base + 3;
                    *(*(matriz + bi) + bj + 1) = base + 2;
                }
            }
        }

        int k_val = (MAX - 2) / 4;
        for (int i = 0; i < halfN; i++) {
            for (int j = 0; j < halfN; j++) {
                if (i < k_val || (i > k_val && i < 2 * k_val + 1) || (i == k_val && j == k_val)) {
                    if (!(i == k_val && j == 0)) {
                        int temp = *(*(matriz + 2 * i) + 2 * j);
                        *(*(matriz + 2 * i) + 2 * j) = *(*(matriz + 2 * i + 1) + 2 * j);
                        *(*(matriz + 2 * i + 1) + 2 * j) = temp;

                        temp = *(*(matriz + 2 * i) + 2 * j + 1);
                        *(*(matriz + 2 * i) + 2 * j + 1) = *(*(matriz + 2 * i + 1) + 2 * j + 1);
                        *(*(matriz + 2 * i + 1) + 2 * j + 1) = temp;
                    }
                }
            }
        }
        for (int i = 0; i < k_val; i++) {
            int temp = *(*(matriz + 2 * i) + 2 * k_val);
            *(*(matriz + 2 * i) + 2 * k_val) = *(*(matriz + 2 * i + 1) + 2 * k_val);
            *(*(matriz + 2 * i + 1) + 2 * k_val) = temp;

            temp = *(*(matriz + 2 * (i + k_val + 1)) + 2 * k_val);
            *(*(matriz + 2 * (i + k_val + 1)) + 2 * k_val) = *(*(matriz + 2 * (i + k_val + 1) + 1) + 2 * k_val);
            *(*(matriz + 2 * (i + k_val + 1) + 1) + 2 * k_val) = temp;
        }

        for (int i = 0; i < halfN; i++) {
            free(*(sub + i));
        }
        free(sub);
    }

    for (ren = 0; ren < MAX; ren++)
    {
        for (col = 0; col < MAX; col++)
        {
            printf("%d\t", *(*(matriz + ren) + col));
        }
        printf("\n");
    }

    for (int i = 0; i < MAX; i++) {
        free(*(matriz + i));
    }
    free(matriz);

    return 0;
}