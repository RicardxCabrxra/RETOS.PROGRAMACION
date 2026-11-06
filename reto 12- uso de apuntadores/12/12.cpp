//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//Hacer una aplicación donde se muestre en el código y en los resultados, diferentes formas de manejar los apuntadores
// en C tanto en variables simples como en arreglos.
#include <stdio.h>

int main() {
    int variable_simple;
    int* apuntador_simple = &variable_simple;

    printf("Ingresa un valor entero para la variable simple: ");
    scanf_s("%d", apuntador_simple);

    int arreglo[3];
    int* apuntador_arreglo = arreglo;

    printf("Ingresa 3 valores enteros para el arreglo:\n");
    for (int i = 0; i < 3; i++) {
        printf("Elemento %d: ", i);
        scanf_s("%d", (apuntador_arreglo + i));
    }

    printf("\n--- Resultados ---\n");
    printf("Variable simple (con apuntador): %d\n", *apuntador_simple);

    printf("Arreglo (con apuntadores):\n");
    for (int i = 0; i < 3; i++) {
        printf("Elemento %d: %d\n", i, *(apuntador_arreglo + i));
    }

    return 0;
}