//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA PIDE 3 NUMEROS Y DETERMINA CUAL DE ELLOS ES EL MAYOR


#include <stdio.h>

int main()
{
    int num1, num2, num3, mayor;

    printf("Ingrese el primer valor: ");
    scanf_s("%d", &num1);
    printf("Ingrese el segundo valor: ");
    scanf_s("%d", &num2);
    printf("Ingrese el tercer valor: ");
    scanf_s("%d", &num3);

    mayor = num1;
    if (num2 > mayor)
        mayor = num2;
    if (num3 > mayor)
        mayor = num3;

    printf("El valor mayor es: %d\n", mayor);

    return 0;
}
