//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA DETERMINA SI UN NUNERO ES PRIMO O NO

#include <stdio.h>

int main()
{
    int n, i, es_primo = 1;
    printf("Ingrese un numero: ");
    scanf_s("%d", &n);
    if (n <= 1) {
        es_primo = 0;
    }
    else {
        for (i = 2; i <= n / 2; i++) {
            if (n % i == 0) {
                es_primo = 0;
                break;
            }
        }
    }
    if (es_primo) {
        printf("El numero es primo\n");
    }
    else {
        printf("El numero no es primo\n");
    }
    return 0;
}
