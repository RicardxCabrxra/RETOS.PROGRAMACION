//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA DETERMINA SI UN NUMERO ES PAR O IMPAR

#include <stdio.h>
int numero;
int main()
{
	printf("Ingrese un numero: ");
	scanf_s("%d", &numero);
	if (numero % 2 == 0)
	{
		printf("El numero es par.\n");
	}
	else
	{
		printf("El numero es impar.\n");
	}
}

