//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
// crea un cuadrado magico de orden impar
#include <stdio.h>
const int MAX = 3;
int main()
{
	int matriz[MAX][MAX];
	int cntdr = 0;
	int ren, col;
	int aren, acol;
	for (ren = 0; ren < MAX; ren++)
	{
		for (col = 0; col < MAX; col++)
		{
			matriz[ren][col] = 0;
		}
	}
	ren = 0; col = MAX / 2;
	for (cntdr = 1; cntdr <= MAX * MAX; cntdr++)
	{
		matriz[ren][col] = cntdr;
		aren = ren; acol = col;
		ren--;
		col++;
		if (ren < 0)
			ren = MAX - 1;
		if (col > MAX - 1)
			col = 0;
		if (matriz[ren][col] != 0)
		{
			ren = aren + 1;
			col = acol;

		}
	}
	for (ren = 0; ren < MAX; ren++)
	{
		for (col = 0; col < MAX; col++)
		{
			printf("%d\t", matriz[ren][col]);
		}
		printf("\n");
	}
}


