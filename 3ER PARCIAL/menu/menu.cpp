#include <stdio.h>
#include "menu.h" // Enlace del encabezado personalizado

int main() {
    int opcion;
    double num1, num2, resultado_d;
    int ent1, ent2, resultado_i;
    int exito;

    do {
        printf("\n==============================\n");
        printf("     MENÚ DE OPERACIONES      \n");
        printf("==============================\n");
        printf("1. Suma\n");
        printf("2. Resta\n");
        printf("3. División (con decimales)\n");
        printf("4. División entera\n");
        printf("5. Residuo (Modulo)\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf_s("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el primer numero: ");
            scanf_s("%lf", &num1);
            printf("Ingrese el segundo numero: ");
            scanf_s("%lf", &num2);
            resultado_d = sumar(num1, num2);
            printf("Resultado: %.2lf + %.2lf = %.2lf\n", num1, num2, resultado_d);
            break;

        case 2:
            printf("Ingrese el primer numero: ");
            scanf_s("%lf", &num1);
            printf("Ingrese el segundo numero: ");
            scanf_s("%lf", &num2);
            resultado_d = restar(num1, num2);
            printf("Resultado: %.2lf - %.2lf = %.2lf\n", num1, num2, resultado_d);
            break;

        case 3:
            printf("Ingrese el dividendo: ");
            scanf_s("%lf", &num1);
            printf("Ingrese el divisor: ");
            scanf_s("%lf", &num2);
            resultado_d = dividir(num1, num2, &exito);
            if (exito) {
                printf("Resultado: %.2lf / %.2lf = %.2lf\n", num1, num2, resultado_d);
            }
            else {
                printf("Error: No se puede dividir entre cero.\n");
            }
            break;

        case 4:
            printf("Ingrese el primer numero entero: ");
            scanf_s("%d", &ent1);
            printf("Ingrese el segundo numero entero: ");
            scanf_s("%d", &ent2);
            resultado_i = division_entera(ent1, ent2, &exito);
            if (exito) {
                printf("Resultado (División entera): %d / %d = %d\n", ent1, ent2, resultado_i);
            }
            else {
                printf("Error: No se puede dividir entre cero.\n");
            }
            break;

        case 5:
            printf("Ingrese el primer numero entero: ");
            scanf_s("%d", &ent1);
            printf("Ingrese el segundo numero entero: ");
            scanf_s("%d", &ent2);
            resultado_i = residuo(ent1, ent2, &exito);
            if (exito) {
                printf("Resultado (Residuo): %d %% %d = %d\n", ent1, ent2, resultado_i);
            }
            else {
                printf("Error: No se puede calcular el residuo con divisor cero.\n");
            }
            break;

        case 6:
            printf("Saliendo del programa. ¡Hasta luego!\n");
            break;

        default:
            printf("Opción no válida. Por favor, intente de nuevo.\n");
        }
    } while (opcion != 6);

    return 0;
}