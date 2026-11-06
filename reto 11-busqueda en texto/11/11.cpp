//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
// Capturar una frase en una cadena de caracteres, después capturar un solo carácter 
// y buscarlo en la frase y mostrar en pantalla si fue hallado y en qué posición
#include <stdio.h>
int buscar(char frase[], char caracter) {
    int i = 0;
    while (frase[i] != '\0') {
        if (frase[i] == caracter) {
            return i;
        }
        i++;
    }
    return -1;
}

int main() {
    char frase[100];
    char caracter;


    printf("Ingresa una frase: ");
    fgets(frase, sizeof(frase), stdin);

    printf("Ingresa el caracter que deseas buscar: ");
    scanf_s("%c", &caracter);


    int posicion = buscar(frase, caracter);
    if (posicion != -1) {
        printf("¡Caracter hallado! Se encuentra en la posicion: %d\n", posicion);
    }
    else {
        printf("El caracter no fue encontrado en la frase.\n");
    }

    return 0;
}