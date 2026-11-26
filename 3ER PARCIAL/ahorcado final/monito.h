// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Encabezado para cargar, desplegar y liberar las fases del ahorcado (maximo 7 fases)

#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>

constexpr int MAX_FASES = 7;
constexpr int TAM_BUFFER_ARCHIVO = 4096;

inline void LimpiarTerminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

// Lee el archivo de fases y extrae cada "Fase " en un arreglo dinamico (hasta 7 fases).
// Retorna el numero de fases cargadas o -1 si ocurre un error al abrir el archivo.
inline int CargarFasesDesdeArchivo(const char* nombreArchivo, char* fases[MAX_FASES]) {
    FILE* archivo = nullptr;
#ifdef _MSC_VER
    if (fopen_s(&archivo, nombreArchivo, "r") != 0 || archivo == nullptr) {
#else
    archivo = std::fopen(nombreArchivo, "r");
    if (archivo == nullptr) {
#endif
        std::printf("Error: No se pudo abrir el archivo '%s'.\n", nombreArchivo);
        std::printf("Asegurate de que esta en la misma carpeta que el programa.\n");
        return -1;
    }

    char contenido[TAM_BUFFER_ARCHIVO];
    size_t bytesLeidos = std::fread(contenido, 1, sizeof(contenido) - 1, archivo);
    contenido[bytesLeidos] = '\0';
    std::fclose(archivo);

    int totalFases = 0;
    char* ptr = std::strstr(contenido, "Fase ");

    while (ptr != nullptr && totalFases < MAX_FASES) {
        char* siguientePtr = std::strstr(ptr + 5, "Fase ");
        size_t longitudFase = (siguientePtr != nullptr)
            ? static_cast<size_t>(siguientePtr - ptr)
            : std::strlen(ptr);

        char* bufferFase = static_cast<char*>(std::malloc((longitudFase + 1) * sizeof(char)));
        if (bufferFase != nullptr) {
            std::memcpy(bufferFase, ptr, longitudFase);
            bufferFase[longitudFase] = '\0';
            fases[totalFases++] = bufferFase;
        }

        ptr = siguientePtr;
    }

    return totalFases;
    }

inline void MostrarFaseActual(char* const fases[MAX_FASES], int totalFases, int indiceFase) {
    if (totalFases <= 0) return;

    if (indiceFase < 0) indiceFase = 0;
    if (indiceFase >= totalFases) indiceFase = totalFases - 1;

    std::printf("%s\n", fases[indiceFase]);
}

inline void LiberarFases(char* fases[MAX_FASES], int totalFases) {
    for (int i = 0; i < totalFases; i++) {
        std::free(fases[i]);
        fases[i] = nullptr;
    }
}