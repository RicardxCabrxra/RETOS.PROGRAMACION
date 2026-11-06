//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA ALMACENA 5 NUMEROS ENTEROS PROPORCIONADOS POR EL USUARIO EN UN ARREGLO Y CALCULA LA SUMA DE LOS ELEMENTOS DEL ARREGLO 
#include <stdio.h>

int main()
{
    int arreglo[5];
    int suma = 0;

    printf("Ingrese 5 valores enteros:\n");
    for (int i = 0; i < 5; i++)
    {
        printf("valor %d: ", i + 1);
        scanf_s("%d", &arreglo[i]);
    }

    for (int i = 0; i < 5; i++)
    {
        suma += arreglo[i];
    }

    printf("La suma de los elementos del arreglo es: %d\n", suma);
    return 0;
}

