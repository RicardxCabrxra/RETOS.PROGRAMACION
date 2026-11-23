//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//encabezao de archivo para el despliegue de las fases del juego del ahorcado
#ifndef DESPLIEGUE_H
#define DESPLIEGUE_H

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FASES 7
#define TAM_BUFFER_ARCHIVO 4096

// Limpia la consola según el sistema operativo
static inline void LimpiarTerminal(void) {
#ifdef _WIN32
    system("cls"); 
#else
    system("clear"); 
#endif
}

// Lee el archivo de fases y extrae cada "Fase " en un arreglo dinámico.
// Retorna el número de fases cargadas o -1 si ocurre un error al abrir el archivo.
static inline int CargarFasesDesdeArchivo(const char* nombreArchivo, char* fases[MAX_FASES]) {
    
        FILE* archivo = fopen("ahorc.txt", "r"); 
        if (archivo == NULL) {
            
                printf("Error: No se pudo abrir el archivo '%s'.\n", "ahorc.txt"); 
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

// Muestra las fases una por una esperando [Enter] y libera la memoria asignada.
static inline void MostrarYDesplegarFases(char* fases[MAX_FASES], int totalFases) {
    int dummy; 
        while ((dummy = getchar()) != '\n' && dummy != EOF); 

            for (int i = 0; i < totalFases; i++) {
               
                    LimpiarTerminal(); 
                    printf("%s", fases[i]); 

                    if (i < totalFases - 1) {
                        
                            printf("\nPresiona [Enter] para ver la siguiente fase...\n"); 
                            while ((dummy = getchar()) != '\n' && dummy != EOF); 
                    }
                    else {
                        printf("\n¡Juego terminado! Presiona [Enter] para salir...\n"); 
                    }
            }

    dummy = getchar(); 

        for (int i = 0; i < totalFases; i++) {
            
                free(fases[i]);
        }
}

#endif // DESPLIEGUE_H