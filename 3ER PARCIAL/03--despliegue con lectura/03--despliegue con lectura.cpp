//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//despliegue de las fases del juego del ahorcado
#include "despliegue.h"

int main(void) {
    char* fases[MAX_FASES] = { NULL };

    int totalFases = CargarFasesDesdeArchivo("ahorc.txt", fases);
    if (totalFases < 0) {
        return 1;
    }

    MostrarYDesplegarFases(fases, totalFases);

    return 0;
}