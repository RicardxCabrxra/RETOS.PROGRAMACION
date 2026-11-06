//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA	DEFINE UN REGISTRO DE ESTUDIANTES, DONDE SE PODRAN AGREGAR, NOMBRE, EDAD Y PROMEDIO DE CADA ESTUDIANTE Y MOSTRAR LOS DATOS EN PANTALLA
#include <stdio.h>

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {
    struct Estudiante alumno;

    printf("--- Registro de Estudiante ---\n");

    printf("Ingrese el nombre del alumno: ");

    fgets(alumno.nombre, sizeof(alumno.nombre), stdin);

    printf("Ingrese la edad: ");
    scanf_s("%d", &alumno.edad);

    printf("Ingrese el promedio: ");
    scanf_s("%f", &alumno.promedio);

    printf("\n--- Datos del Estudiante Registro ---\n");
    printf("Nombre: %s", alumno.nombre);
    printf("Edad: %d anhos\n", alumno.edad);
    printf("Promedio: %.2f\n", alumno.promedio);

    return 0;
}