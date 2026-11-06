//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA CALCULA EL FACTORIAL DE UN NUMERO ENTERO POSITIVO PROPORCIONADO POR EL USUARIO
#include <stdio.h>

int main()
{
    int n, i;
    long long factorial = 1;

    printf("Ingrese un numero entero positivo: ");
    scanf_s("%d", &n);

    if (n < 0) {
        printf("Error: Ingrese un numero entero positivo.\n");
    }
    else {
        for (i = 1; i <= n; i++) {
            factorial *= i;
        }
        printf("El factorial de %d es %lld\n", n, factorial);
    }

    return 0;
}

