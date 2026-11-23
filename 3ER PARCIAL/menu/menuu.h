#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <stdio.h>

// Declaración e implementación de la Suma
double sumar(double a, double b) {
    return a + b;
}

// Declaración e implementación de la Resta
double restar(double a, double b) {
    return a - b;
}

// Declaración e implementación de la División con decimales
double dividir(double a, double b, int* exito) {
    if (b == 0) {
        *exito = 0; // Indicador de error (división por cero)
        return 0;
    }
    *exito = 1;
    return a / b;
}

// Declaración e implementación de la División entera
int division_entera(int a, int b, int* exito) {
    if (b == 0) {
        *exito = 0;
        return 0;
    }
    *exito = 1;
    return a / b;
}

// Declaración e implementación del Residuo (Módulo)
int residuo(int a, int b, int* exito) {
    if (b == 0) {
        *exito = 0;
        return 0;
    }
    *exito = 1;
    return a % b;
}

#endif#pragma once
