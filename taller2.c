#include <stdio.h>

#define MAX 100

int main() {
    int hora_ingreso, horas[MAX], hora_salida, minutos[MAX], minuto_ingreso, minuto_salida, clientes = 0;
    float pagos[MAX], ingresos_dia = 0, ingresos_mes = 0, total;
    char es_domingo, continuar = 's';
    
    while (continuar == 's' || continuar == 'S'){
        if (clientes > MAX){
            printf("Se ha alcanzado el numero maximo de clientes del dia.\n");
            break;
        }

        int i = 0;
        while (i == 0){
            printf("Ingrese la hora de ingreso al estacionado(solo la hora, 6-22): ");
            scanf("%d", &hora_ingreso);
            if (hora_ingreso >= 23){
                printf("Hora invalida. \n Ingrese una hora entre 6 y 22: ");
                scanf("%d", &hora_ingreso);
            }
            else {
                i=1;
            }
        }

        while (i == 1){
            printf("Ingrese el minuto de ingreso al estacionamiento");
            scanf("%d", &minuto_ingreso);
            if (minuto_ingreso >= 61){
                printf("minuto invalido. \n Ingrese un minuto entre 0 y 60: ");
                scanf("%d", &minuto_ingreso);
            }
            else {
                i=2;
            }
        }

        while (i == 2){
            printf("Ingrese la hora de salida al estacionado(solo la hora, 6-22): ");
            scanf("%d", &hora_salida);
            if (hora_salida >= 23){
                printf("Hora invalida. \n Ingrese un minuto entre 6 y 22: ");
                scanf("%d", &hora_salida);
            }
            else {
                i=3;
            }
        }
        while (i == 3){
            printf("Ingrese el minuto de salida al estacionamiento");
            scanf("%d", &minuto_salida);
            if (minuto_salida >= 61){
                printf("minuto invalido. \n Ingrese un minuto entre 0 y 60: ");
                scanf("%d", &minuto_salida);
            }
            else {
                i=4;
            }
        }
        // Cálculo del costo
        horas[MAX] = hora_salida - hora_ingreso;
        minutos[MAX] = minuto_salida - minuto_ingreso;

        if (horas[MAX] == 0 && minutos[MAX] <= 10){
        total = 0;
        }
        else {
            if (horas[MAX] == 0 && minutos[MAX] <= 25){
            total = 3;
        }
            else {
            if (horas[MAX] == 0){
            total = 10;
            }
        }
    }
    if (es_domingo == 's' || es_domingo == 'S') {
            total *= 0.8;
    }

    total = total + total;
    ingresos_mes = ingresos_mes + total;
    ingresos_dia = ingresos_dia + total;

    clientes++;

    printf("¿Desea ingresar otro cliente? (s/n): ");
    scanf(" %c", &continuar);
    }
    // Imprimir tabla diaria
    printf("\n-------------------------------\n");
    printf("Horas/min     | $ a pagar\n");
    printf("-------------------------------\n");

    for (int k = 0; k < clientes; k++) {
        printf("%2d h %2d min   | $%.2f\n", horas[k], minutos[k], pagos[k]);
    }
    // Mostrar resumen
    printf("-------------------------------\n");
    printf("Total ingresado hoy: $%.2f\n", ingresos_dia);
    printf("Histórico del mes:  $%.2f\n", ingresos_mes);

    return 0;
}