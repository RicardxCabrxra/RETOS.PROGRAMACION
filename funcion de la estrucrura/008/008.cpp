// ESCUELA: UNIVERSIDAD POLITÉCNICA DE TULANCINGO
// CARRERA: SISTEMAS ELECTRÓNICOS Y TELECOMUNICACIONES
// MATERIA: PROGRAMACIÓN ESTRUCTURADA
// NOMBRE: RICARDO SANTIAGO CABRERA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 3

struct Materia {
    char nombreMateria[30];
    float calificacion;
};

struct Estudiante {
    int id;
    char nombre[50];
    struct Materia materias[MAX_MATERIAS];
    float promedioGeneral;
};

void registrarEstudiante(struct Estudiante* e, int id) {
    e->id = id;
    printf("\n--- Registro de Estudiante ID: %d ---\n", id);
    printf("Nombre completo: ");
    getchar(); // Limpiar buffer
    fgets(e->nombre, sizeof(e->nombre), stdin);
    e->nombre[strcspn(e->nombre, "\n")] = 0;

    float suma = 0;
    for (int i = 0; i < MAX_MATERIAS; i++) {
        printf("Materia %d - Nombre: ", i + 1);
        scanf_s("%s", e->materias[i].nombreMateria, (unsigned int)sizeof(e->materias[i].nombreMateria));
        printf("Materia %d - Calificacion: ", i + 1);
        scanf_s("%f", &e->materias[i].calificacion);
        suma += e->materias[i].calificacion;
    }
    e->promedioGeneral = suma / MAX_MATERIAS;
}

void mostrarReporte(const struct Estudiante* e) {
    printf("\n========================================\n");
    printf(" REPORTE ACADEMICO - ID: %d\n", e->id);
    printf("========================================\n");
    printf("Estudiante: %s\n", e->nombre);
    printf("----------------------------------------\n");
    for (int i = 0; i < MAX_MATERIAS; i++) {
        printf("  * %s: %.2f\n", e->materias[i].nombreMateria, e->materias[i].calificacion);
    }
    printf("----------------------------------------\n");
    printf("Promedio General: %.2f\n", e->promedioGeneral);
    printf("========================================\n");
}

int main() {
    int n;
    printf("Ingrese el numero de estudiantes a registrar: ");
    scanf_s("%d", &n);

    struct Estudiante* lista = (struct Estudiante*)malloc(n * sizeof(struct Estudiante));
    if (lista == NULL) {
        printf("Error de asignacion de memoria.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        registrarEstudiante(&lista[i], i + 1);
    }

    printf("\n\n=== LISTADO GENERAL DE ESTUDIANTES ===\n");
    for (int i = 0; i < n; i++) {
        mostrarReporte(&lista[i]);
    }

    free(lista);
    return 0;
}