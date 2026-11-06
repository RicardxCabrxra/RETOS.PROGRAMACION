//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//lee un archivo de texto y lo muestra en pantalla
#include <stdio.h>
#include <stdlib.h>

int main() {
    int giroMotor = 15000;
    FILE* archivo;
    char buffer[256];
    if (fopen_s(&archivo, "ARCHH.txt", "w") != 0) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Hola mundo desde el lenguaje C.\n");
    fprintf(archivo, "Giro del motor: %d RPM\n", giroMotor);
    fputs("Esta es una linea adicional.\n", archivo);

    fclose(archivo);
    printf("--- Archivo escrito con exito ---\n\n");


    if (fopen_s(&archivo, "ARCHH.txt", "r") != 0) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    printf("--- Contenido leido del archivo ---\n");


    while (fgets(buffer, sizeof(buffer), archivo) != NULL) {
        printf("%s", buffer);
    }

    fclose(archivo);
    printf("------------------------------------\n");

    return 0;
}