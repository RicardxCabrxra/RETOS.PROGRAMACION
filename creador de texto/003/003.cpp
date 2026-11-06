//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//crea un archivo de texto y escribe en el
#include <stdio.h>

int main() {
    int giroMotor = 15000;
    FILE* archivo;

    archivo = fopen("C:\\Users\\lricar\\OneDrive\\ARCHH", "w");

    if (archivo == NULL) {
        printf("Error al crear o abrir el archivo.\n");
        return 1;
    }

    fprintf(archivo, "Hola mundo desde el lenguaje C.\n");
    fprintf(archivo, "Giro del motor: %d RPM\n", giroMotor);
    fputs("Esta es una linea adicional.\n", archivo);

    fclose(archivo);
    printf("Archivo escrito con exito.\n");

    return 0;
}