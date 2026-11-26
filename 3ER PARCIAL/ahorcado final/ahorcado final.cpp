// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Programa principal: integra monito.h y diccionario.h con un limite de 7 fases

#include "monito.h"
#include "diccionario.h"

int main() {
    configurar_consola_utf8();

    char* fases[MAX_FASES] = { nullptr };
    int totalFases = CargarFasesDesdeArchivo("ahorc.txt", fases);
    if (totalFases <= 0) {
        return 1;
    }

    char palabra_elegida[MAX_LINEA];
    if (!cargar_palabra_aleatoria("diccionario.txt", palabra_elegida, sizeof(palabra_elegida))) {
        LiberarFases(fases, totalFases);
        return 1;
    }

    JuegoDiccionario juego;
    inicializar_juego(&juego, palabra_elegida);

    bool completado = false;
    int faseActual = 0;
    int limiteFases = (totalFases < MAX_FASES) ? totalFases : MAX_FASES;
    char mensaje[200] = "Comienza el juego. Adivina una letra.";

    while (!completado && faseActual < limiteFases - 1) {
        LimpiarTerminal();
        MostrarFaseActual(fases, totalFases, faseActual);

        std::printf("\n%s\n", mensaje);
        std::printf("Palabra o frase oculta: %s\n", juego.espejo);
        std::printf("Fase: %d de %d | Intentos: %d\n", faseActual + 1, limiteFases, juego.intentos);
        std::printf("Ingrese una letra: ");

        char entrada[16];
#ifdef _MSC_VER
        if (scanf_s("%15s", entrada, static_cast<unsigned int>(sizeof(entrada))) != 1) {
#else
        if (std::scanf("%15s", entrada) != 1) {
#endif
            break;
        }

        bool encontrado = procesar_intento(&juego, entrada, &completado);

        if (encontrado) {
            std::snprintf(mensaje, sizeof(mensaje), "Bien hecho. La letra '%s' esta en el texto.", entrada);
        }
        else {
            faseActual++;
            std::snprintf(mensaje, sizeof(mensaje), "La letra '%s' no esta o ya fue adivinada (fallo).", entrada);
        }
        }

    LimpiarTerminal();
    MostrarFaseActual(fases, totalFases, faseActual);

    if (completado) {
        std::printf("\n¡FELICIDADES! Has completado '%s' en %d intentos (Fase %d de %d).\n",
            juego.texto, juego.intentos, faseActual + 1, limiteFases);
    }
    else {
        std::printf("\n¡HAS PERDIDO! Se alcanzo el limite de %d fases.\n", limiteFases);
        std::printf("La palabra o frase era: '%s' (Total de intentos: %d).\n",
            juego.texto, juego.intentos);
    }

    LiberarFases(fases, totalFases);
    std::printf("El juego ha terminado.\n");

    return 0;
    }