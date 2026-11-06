//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
//ESTE PROGRAMA EJECUTA UNA CALCULADORA BASICA CON OPERACIONES DE SUMA, RESTA, MULTIPLICACION Y DIVISION
#include <stdio.h>

int main() {
    char operador;
    double num1, num2, resultado;

    
    printf("Introduce un operador (+, -, *, /): ");
    scanf_s(" %c", &operador);

    
    printf("Introduce dos numeros separados por espacio: ");
    scanf_s("%lf %lf", &num1, &num2);

    
    switch (operador) {
    case '+':
        resultado = num1 + num2;
        printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado);
        break;

    case '-':
        resultado = num1 - num2;
        printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado);
        break;

    case '*':
        resultado = num1 * num2;
        printf("Resultado: %.2lf * %.2lf = %.2lf\n", num1, num2, resultado);
        break;

    case '/':
       
        if (num2 != 0) {
            resultado = num1 / num2;
            printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado);
        }
        else {
            printf("Error: No se puede dividir entre cero.\n");
        }
        break;

    default:
        printf("Error: Operador no valido.\n");
    }

    return 0;
}