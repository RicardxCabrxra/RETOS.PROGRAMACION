//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA SOLICITA AL USUARIO UN NUMERO Y MUESTRA SU TABLA DE MULTIPLICAR DEL 1 AL 10


#include <stdio.h>

int main()
{
    int numero;
    printf("Ingrese un numero: ");
    scanf_s("%d", &numero);

    for (int i = 1; i <= 10; i++)
    {
        printf("%d x %d = %d\n", numero, i, numero * i);
    }

    return 0;
}
