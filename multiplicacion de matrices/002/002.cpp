//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//multiplicacion de matrices

#include <stdio.h>

const int MAX = 3;

int main() {

    int matriz1[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int matriz2[MAX][MAX] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int resultado[MAX][MAX];
    int ren, col, k;


    for (ren = 0; ren < MAX; ren++) {
        for (col = 0; col < MAX; col++) {
            resultado[ren][col] = 0;
        }
    }


    for (ren = 0; ren < MAX; ren++) {
        for (col = 0; col < MAX; col++) {
            for (k = 0; k < MAX; k++) {
                resultado[ren][col] += matriz1[ren][k] * matriz2[k][col];
            }
        }
    }

    printf("Resultado de la multiplicacion de matrices:\n");
    for (ren = 0; ren < MAX; ren++) {
        for (col = 0; col < MAX; col++) {
            printf("%d \t", resultado[ren][col]);
        }
        printf("\n");
    }

    return 0;
}