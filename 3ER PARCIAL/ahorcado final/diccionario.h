// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Encabezado para seleccionar palabras desde "diccionario.txt" y gestionar los intentos UTF-8

#pragma once

#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#ifdef _WIN32
#include <windows.h>
#endif

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

inline void configurar_consola_utf8() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif
}

inline void limpiar_salto_linea(char* str) {
    size_t len = std::strlen(str);
    while (len > 0 && (str[len - 1] == '\n' || str[len - 1] == '\r')) {
        str[len - 1] = '\0';
        len--;
    }
}

inline int normalizar_caracter_utf8(const unsigned char* s, char clave_out[8]) {
    std::memset(clave_out, 0, 8);

    if (s[0] < 0x80) {
        unsigned char c = s[0];
        if (c >= 'A' && c <= 'Z') {
            c = static_cast<unsigned char>(c + ('a' - 'A'));
        }
        clave_out[0] = static_cast<char>(c);
        return 1;
    }

    if ((s[0] == 0xC2 || s[0] == 0xC3) && s[1] != '\0') {
        unsigned int codepoint = (static_cast<unsigned int>(s[0] & 0x1F) << 6) |
            static_cast<unsigned int>(s[1] & 0x3F);

        if ((codepoint >= 0xC0 && codepoint <= 0xD6 && codepoint != 0xD7) ||
            (codepoint >= 0xD8 && codepoint <= 0xDE)) {
            codepoint += 0x20;
        }

        if (codepoint == 0xE1 || codepoint == 0xE4) {
            clave_out[0] = 'a';
        }
        else if (codepoint == 0xE9) {
            clave_out[0] = 'e';
        }
        else if (codepoint == 0xED) {
            clave_out[0] = 'i';
        }
        else if (codepoint == 0xF3) {
            clave_out[0] = 'o';
        }
        else if (codepoint == 0xFA || codepoint == 0xFC) {
            clave_out[0] = 'u';
        }
        else {
            clave_out[0] = static_cast<char>(0xC0 | ((codepoint >> 6) & 0x1F));
            clave_out[1] = static_cast<char>(0x80 | (codepoint & 0x3F));
        }
        return 2;
    }

    clave_out[0] = static_cast<char>(s[0]);
    return 1;
}

inline bool cargar_palabra_aleatoria(const char* ruta_archivo, char* destino, size_t tam_destino) {
    FILE* archivo = nullptr;
#ifdef _MSC_VER
    if (fopen_s(&archivo, ruta_archivo, "r") != 0 || archivo == nullptr) {
#else
    archivo = std::fopen(ruta_archivo, "r");
    if (archivo == nullptr) {
#endif
        std::printf("Error: No se pudo abrir '%s'.\n", ruta_archivo);
        return false;
    }

    char (*palabras)[MAX_LINEA] = new char[MAX_PALABRAS][MAX_LINEA];
    int total_palabras = 0;
    char buffer[MAX_LINEA];

    while (total_palabras < MAX_PALABRAS && std::fgets(buffer, sizeof(buffer), archivo) != nullptr) {
        limpiar_salto_linea(buffer);
        if (buffer[0] != '\0') {
#ifdef _MSC_VER
            strcpy_s(palabras[total_palabras], MAX_LINEA, buffer);
#else
            std::strcpy(palabras[total_palabras], buffer);
#endif
            total_palabras++;
        }
    }
    std::fclose(archivo);

    if (total_palabras == 0) {
        std::printf("Error: El archivo '%s' esta vacio.\n", ruta_archivo);
        delete[] palabras;
        return false;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int indice = std::rand() % total_palabras;

#ifdef _MSC_VER
    strncpy_s(destino, tam_destino, palabras[indice], _TRUNCATE);
#else
    std::strncpy(destino, palabras[indice], tam_destino - 1);
    destino[tam_destino - 1] = '\0';
#endif

    delete[] palabras;
    return true;
    }

inline void inicializar_juego(JuegoDiccionario * juego, const char* palabra) {
#ifdef _MSC_VER
    strncpy_s(juego->texto, MAX_LINEA, palabra, _TRUNCATE);
#else
    std::strncpy(juego->texto, palabra, MAX_LINEA - 1);
    juego->texto[MAX_LINEA - 1] = '\0';
#endif
    juego->espejo[0] = '\0';
    juego->num_chars = 0;
    juego->intentos = 0;

    char clave_dummy[8];
    int pos_byte = 0;

    while (juego->texto[pos_byte] != '\0' && juego->num_chars < MAX_LINEA) {
        int bytes_char = normalizar_caracter_utf8(
            reinterpret_cast<const unsigned char*>(&juego->texto[pos_byte]), clave_dummy);

        juego->indices_byte[juego->num_chars] = pos_byte;
        juego->longitudes_byte[juego->num_chars] = bytes_char;

        if (bytes_char == 1 && juego->texto[pos_byte] == ' ') {
#ifdef _MSC_VER
            strcat_s(juego->espejo, sizeof(juego->espejo), " ");
#else
            std::strcat(juego->espejo, " ");
#endif
            juego->descubierto[juego->num_chars] = true;
        }
        else {
#ifdef _MSC_VER
            strcat_s(juego->espejo, sizeof(juego->espejo), "_");
#else
            std::strcat(juego->espejo, "_");
#endif
            juego->descubierto[juego->num_chars] = false;
        }

        juego->num_chars++;
        pos_byte += bytes_char;
    }
}

inline bool procesar_intento(JuegoDiccionario * juego, const char* entrada, bool* completado) {
    char clave_entrada[8];
    normalizar_caracter_utf8(reinterpret_cast<const unsigned char*>(entrada), clave_entrada);

    juego->intentos++;
    bool encontrado = false;
    juego->espejo[0] = '\0';
    *completado = true;

    char clave_texto[8];

    for (int i = 0; i < juego->num_chars; i++) {
        int idx = juego->indices_byte[i];
        int len = juego->longitudes_byte[i];

        if (len == 1 && juego->texto[idx] == ' ') {
#ifdef _MSC_VER
            strcat_s(juego->espejo, sizeof(juego->espejo), " ");
#else
            std::strcat(juego->espejo, " ");
#endif
            continue;
        }

        normalizar_caracter_utf8(
            reinterpret_cast<const unsigned char*>(&juego->texto[idx]), clave_texto);

        if (!juego->descubierto[i] && std::strcmp(clave_texto, clave_entrada) == 0) {
            juego->descubierto[i] = true;
            encontrado = true;
        }

        if (juego->descubierto[i]) {
#ifdef _MSC_VER
            strncat_s(juego->espejo, sizeof(juego->espejo), &juego->texto[idx], static_cast<size_t>(len));
#else
            std::strncat(juego->espejo, &juego->texto[idx], static_cast<size_t>(len));
#endif
        }
        else {
#ifdef _MSC_VER
            strcat_s(juego->espejo, sizeof(juego->espejo), "_");
#else
            std::strcat(juego->espejo, "_");
#endif
            * completado = false;
        }
    }

    return encontrado;
}