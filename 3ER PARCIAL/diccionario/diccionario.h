// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// ENCABEZADO CON ESTRUCTURAS Y DECLARACIONES PARA EL JUEGO DE ADIVINANZA
// CON LECTURA ALEATORIA DESDE "diccionario.txt" Y SOPORTE UTF-8.

#pragma once

#include <cstddef>

constexpr int MAX_LINEA = 256;
constexpr int MAX_PALABRAS = 2000;

struct JuegoDiccionario {
    char texto[MAX_LINEA];
    char espejo[MAX_LINEA * 2];
    bool descubierto[MAX_LINEA];
    int indices_byte[MAX_LINEA];
    int longitudes_byte[MAX_LINEA];
    int num_chars;
    int intentos;
};

void configurar_consola_utf8();
void limpiar_salto_linea(char* str);
int normalizar_caracter_utf8(const unsigned char* s, char clave_out[8]);
bool cargar_palabra_aleatoria(const char* ruta_archivo, char* destino, size_t tam_destino);
void inicializar_juego(JuegoDiccionario* juego, const char* palabra);
bool procesar_intento(JuegoDiccionario* juego, const char* entrada, bool* completado);