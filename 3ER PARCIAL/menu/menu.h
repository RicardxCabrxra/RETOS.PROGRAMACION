#ifndef MENU_H
#define MENU_H  

#include <stdio.h>


double sumar(double a, double b) {
    return a + b;
}

double restar(double a, double b) {
    return a - b;
}


double dividir(double a, double b, int* exito) {
    if (b == 0) {
        *exito = 0;
        return 0;
    }
    *exito = 1;
    return a / b;
}


int division_entera(int a, int b, int* exito) {
    if (b == 0) {
        *exito = 0;
        return 0;
    }
    *exito = 1;
    return a / b;
}


int residuo(int a, int b, int* exito) {
    if (b == 0) {
        *exito = 0;
        return 0;
    }
    *exito = 1;
    return a % b;
}

#endif#pragma once
