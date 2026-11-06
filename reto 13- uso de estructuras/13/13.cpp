//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//Hacer una aplicación donde se muestre en el código y en los resultados, la forma de utilizar
// estructuras en C como variable simple.
#include <stdio.h>
#include <string.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante alumno_simple;
    struct Estudiante grupo[2];

    printf("--- Variable Simple ---\n");
    printf("Nombre: ");
    fgets(alumno_simple.nombre, sizeof(alumno_simple.nombre), stdin);
    alumno_simple.nombre[strcspn(alumno_simple.nombre, "\n")] = 0;
    printf("Edad: ");
    scanf_s("%d", &alumno_simple.edad);
    printf("Promedio: ");
    scanf_s("%f", &alumno_simple.promedio);
    getchar();

    printf("\n--- Arreglo de Estructuras ---\n");
    for (int i = 0; i < 2; i++) {
        printf("Estudiante %d Nombre: ", i + 1);
        fgets(grupo[i].nombre, sizeof(grupo[i].nombre), stdin);
        grupo[i].nombre[strcspn(grupo[i].nombre, "\n")] = 0;
        printf("Estudiante %d Edad: ", i + 1);
        scanf_s("%d", &grupo[i].edad);
        printf("Estudiante %d Promedio: ", i + 1);
        scanf_s("%f", &grupo[i].promedio);
        getchar();
    }

    printf("\n=== RESULTADOS ===\n");
    printf("Variable Simple -> Nombre: %s, Edad: %d, Promedio: %.2f\n",
        alumno_simple.nombre, alumno_simple.edad, alumno_simple.promedio);

    for (int i = 0; i < 2; i++) {
        printf("Arreglo[%d] -> Nombre: %s, Edad: %d, Promedio: %.2f\n",
            i, grupo[i].nombre, grupo[i].edad, grupo[i].promedio);
    }

    return 0;
}