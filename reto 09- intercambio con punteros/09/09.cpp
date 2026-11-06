//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA CAPTURA DOS NUMEROS Y LOS INTERCAMBIA USANDO PUNTEROS
#include <stdio.h>

int main()
{
	int a, b;
	int* p1, * p2;

	printf("Ingrese el primer valor: ");
	scanf_s("%d", &a);
	printf("Ingrese el segundo valor: ");
	scanf_s("%d", &b);

	p1 = &a;
	p2 = &b;
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	printf("Despues del intercambio:\n");
	printf("Primer valor: %d\n", a);
	printf("Segundo valor: %d\n", b);

	return 0;
}
