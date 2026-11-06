//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA SOLICITA UNA CADENA DE TEXTO Y CUENTA EL NUMERO DE VOCALES QUE CONTIENE 

#include <stdio.h>
int main()
{
    char cadena[100];
    int i, contador = 0;

    printf("Ingresa una palabra: ");
    fgets(cadena, sizeof(cadena), stdin);

    for (i = 0; cadena[i] != '\0'; i++) {
        switch (cadena[i]) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
        case 'A':
        case 'E':
        case 'I':
        case 'O':
        case 'U':
            contador++;
            break;
        default:

            break;
        }
    }

    printf("El numero de vocales en la cadena es: %d\n", contador);

    return 0;
}