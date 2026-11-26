// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Encabezado para cargar, desplegar y liberar las 7 fases del ahorcado

#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FASES 7
#define TAM_BUFFER_ARCHIVO 4096

static inline void LimpiarTerminal(void) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Lee el archivo de fases y extrae cada "Fase " en un arreglo dinamico (hasta 7 fases).
// Retorna el numero de fases cargadas o -1 si ocurre un error al abrir el archivo.
static inline int CargarFasesDesdeArchivo(const char* nombreArchivo, char* fases[MAX_FASES]) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo '%s'.\n", nombreArchivo);
        printf("Asegurate de que esta en la misma carpeta que el programa.\n");
        return -1;
    }

    char contenido[TAM_BUFFER_ARCHIVO];
    size_t bytesLeidos = fread(contenido, 1, sizeof(contenido) - 1, archivo);
    contenido[bytesLeidos] = '\0';
    fclose(archivo);

    int totalFases = 0;
    char* ptr = strstr(contenido, "Fase ");

    while (ptr != NULL && totalFases < MAX_FASES) {
        char* siguientePtr = strstr(ptr + 5, "Fase ");
        size_t longitudFase = (siguientePtr != NULL)
            ? (size_t)(siguientePtr - ptr)
            : strlen(ptr);

        char* bufferFase = (char*)malloc((longitudFase + 1) * sizeof(char));
        if (bufferFase != NULL) {
            strncpy(bufferFase, ptr, longitudFase);
            bufferFase[longitudFase] = '\0';
            fases[totalFases++] = bufferFase;
        }

        ptr = siguientePtr;
    }

    return totalFases;
}

static inline void MostrarFaseActual(char* const fases[MAX_FASES], int totalFases, int indiceFase) {
    if (totalFases <= 0) return;

    if (indiceFase < 0) indiceFase = 0;
    if (indiceFase >= totalFases) indiceFase = totalFases - 1;

    printf("%s\n", fases[indiceFase]);
}

static inline void LiberarFases(char* fases[MAX_FASES], int totalFases) {
    for (int i = 0; i < totalFases; i++) {
        free(fases[i]);
        fases[i] = NULL;
    }
}