// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Encabezado para capturar y gestionar la palabra o frase a adivinar

#pragma once

#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_TEXTO 101

typedef struct {
    char texto[MAX_TEXTO];
    char espejo[MAX_TEXTO];
    int total_letras;
    int intentos;
} JuegoPalabra;

static inline void LimpiarBufferEntrada(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

static inline void PedirPalabra(JuegoPalabra* juego) {
    int j;
    juego->total_letras = 0;
    juego->intentos = 0;

    printf("Ingrese una palabra o frase a adivinar: ");
    fgets(juego->texto, sizeof(juego->texto), stdin);
    juego->texto[strcspn(juego->texto, "\n")] = '\0';

    for (j = 0; juego->texto[j] != '\0'; j++) {
        if (juego->texto[j] == ' ') {
            juego->espejo[j] = ' ';
        }
        else {
            juego->espejo[j] = '_';
            juego->total_letras++;
        }
    }
    juego->espejo[j] = '\0';
}

static inline bool IntentarLetra(JuegoPalabra* juego, char letra, char* mensaje, size_t tamMensaje) {
    bool encontrado = false;
    juego->intentos++;

    for (int j = 0; juego->texto[j] != '\0'; j++) {
        if (tolower((unsigned char)juego->texto[j]) == tolower((unsigned char)letra) &&
            juego->espejo[j] == '_') {
            juego->espejo[j] = juego->texto[j];
            encontrado = true;
        }
    }

    if (encontrado) {
        snprintf(mensaje, tamMensaje, "Bien hecho. La letra '%c' esta en el texto.", letra);
    }
    else {
        snprintf(mensaje, tamMensaje, "La letra '%c' no esta o ya fue adivinada (fallo).", letra);
    }

    return encontrado;
}

static inline bool PalabraCompletada(const JuegoPalabra* juego) {
    return strcmp(juego->texto, juego->espejo) == 0;
}