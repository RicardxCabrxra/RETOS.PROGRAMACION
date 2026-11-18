//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//DESPLIEGUE DE FASES DEL AHORCADO
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpiarTerminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {

    FILE* archivo = fopen("Fases_del_Ahorcado__7_fases_.txt", "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir el archivo 'Fases_del_Ahorcado__7_fases_.txt'.\n");
        printf("Asegurate de que este en la misma carpeta que el programa.\n");
        return 1;
    }

  
    char contenido[4096];
    size_t bytesLeidos = fread(contenido, 1, sizeof(contenido) - 1, archivo);
    contenido[bytesLeidos] = '\0';
    fclose(archivo);


    char* fases[7];
    int totalFases = 0;

  
    char* ptr = strstr(contenido, "Fase ");
    while (ptr != NULL && totalFases < 7) {

        char* siguientePtr = strstr(ptr + 5, "Fase ");

        size_t longitudFase = 0;
        if (siguientePtr != NULL) {
            longitudFase = siguientePtr - ptr;
        }
        else {
            longitudFase = strlen(ptr);
        }

        char* bufferFase = (char*)malloc((longitudFase + 1) * sizeof(char));
        if (bufferFase != NULL) {
            
            strncpy(bufferFase, ptr, longitudFase);
            bufferFase[longitudFase] = '\0'; 
            fases[totalFases++] = bufferFase;
        }

        ptr = siguientePtr;
    }


    int dummy;
    while ((dummy = getchar()) != '\n' && dummy != EOF);

 
    for (int i = 0; i < totalFases; i++) {
        limpiarTerminal();        
        printf("%s", fases[i]);     

        if (i < totalFases - 1) {
            printf("\nPresiona [Enter] para ver la siguiente fase...");
        }
        else {
            printf("\n¡Juego terminado! Presiona [Enter] para salir...");
        }

       
        dummy = getchar();

        
        free(fases[i]);
    }

    return 0;
}