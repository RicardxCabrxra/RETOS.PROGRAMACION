//ESCUELA--UNIVERSIDAD POLITECNICA DE TULANCINGO
//CARRERA--SISTEMAS ELECTRONICOS Y TELECOMUNICACIONES
//MATERIA--PROGRAMACION ESTRUCTURADA
//NOMBRE--RICARDO SANTIAGO CABRERA
// ESTE RPOGRAMA MUESTRA UN MENSAJE LETRA POR LETRA, PIDIENDO AL USUARIO SI DESEA MOSTRAR LA SIGUIENTE LETRA O NO. SI EL USUARIO DECIDE NO MOSTRARLA, EL PROGRAMA SE DETIENE Y MUESTRA EL MENSAJE ACUMULADO HASTA ESE MOMENTO.  
#include <stdio.h>
#include <windows.h>

void Limpiar_pantalla() {
    printf("\033[2J\033[H");
}

int main() {
    char texto[] = "MENSAJE DE PRUEBA\n";
    char opcion;
    char acumulado[100] = "";
    int j = 0;


    for (int i = 0; texto[i] != '\0'; i++) {
        Limpiar_pantalla();
        printf("Mensaje actual: %s\n", acumulado);
        printf("¿Deseas mostrar la siguiente letra? (s/n): ");
        scanf_s(" %c", &opcion);

        if (opcion == 's' || opcion == 'S') {
            acumulado[j] = texto[i];
            j++;
            acumulado[j] = '\0';
        }
        else if (opcion == 'n' || opcion == 'N') {
            printf("\nHas decidido detener el programa.\n");
            break;
        }
        else {
            printf("\nOpción inválida. Presiona 's' para continuar o 'n' para salir.\n");
            Sleep(1000);
            i--;
        }
    }
    Limpiar_pantalla();
    printf("Mensaje final: %s\n", acumulado);
    printf("Programa finalizado.\n");

    return 0;
}