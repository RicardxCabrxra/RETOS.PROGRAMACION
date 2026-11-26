// ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
// CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
// MATERIA--PROGRAMACION ESTRUCTURADA
// NOMBRE--RICARDO SANTIAGO CABRERA
// Programa principal: integra palabra.h y monitos.h con un maximo de 7 fases

#include "palabra.h"
#include "monitos.h"

int main(void) {
    char* fases[MAX_FASES] = { NULL };
    int totalFases = CargarFasesDesdeArchivo("ahorc.txt", fases);

    if (totalFases <= 0) {
        printf("No se pudieron cargar las fases desde 'ahorc.txt'.\n");
        return 1;
    }

    JuegoPalabra juego;
    PedirPalabra(&juego);

    // Si el usuario ingresa una cadena vacia
    if (juego.texto[0] == '\0') {
        printf("No ingresaste ningun texto.\n");
        LiberarFases(fases, totalFases);
        return 0;
    }

    int faseActual = 0; // Empieza en la fase 0 (primera de las 7 fases)
    int maxFasesPermitidas = (totalFases < MAX_FASES) ? totalFases : MAX_FASES;
    char letra;
    char mensaje[200] = "Comienza el juego. Adivina una letra.";

    while (!PalabraCompletada(&juego) && faseActual < maxFasesPermitidas - 1) {
        LimpiarTerminal();
        MostrarFaseActual(fases, totalFases, faseActual);

        printf("\n%s\n", mensaje);
        printf("Palabra oculta: %s\n", juego.espejo);
        printf("Fase actual: %d de %d | Intentos totales: %d\n",
            faseActual + 1, maxFasesPermitidas, juego.intentos);
        printf("Ingrese una letra: ");

        if (scanf_s(" %c", &letra) != 1) {
            LimpiarBufferEntrada();
            snprintf(mensaje, sizeof(mensaje), "Entrada no valida. Intenta de nuevo.");
            continue;
        }
        LimpiarBufferEntrada();

        bool acerto = IntentarLetra(&juego, letra, mensaje, sizeof(mensaje));
        if (!acerto) {
            faseActual++; // Avanza a la siguiente fase al fallar
        }
    }

    LimpiarTerminal();
    MostrarFaseActual(fases, totalFases, faseActual);

    if (PalabraCompletada(&juego)) {
        printf("\n¡FELICIDADES! Has completado '%s' en %d intentos (Fase %d de %d).\n",
            juego.texto, juego.intentos, faseActual + 1, maxFasesPermitidas);
    }
    else {
        printf("\n¡HAS PERDIDO! Se alcanzaron las %d fases.\n", maxFasesPermitidas);
        printf("La palabra o frase era: '%s' (Total de intentos: %d).\n",
            juego.texto, juego.intentos);
    }

    LiberarFases(fases, totalFases);
    printf("Memoria liberada. El juego ha terminado.\n");

    return 0;
}