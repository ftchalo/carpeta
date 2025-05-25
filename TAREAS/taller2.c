#include <stdio.h>

#define MAX 100

int main() {
    int hora_ingreso, horas[MAX], hora_salida, minutos[MAX], minuto_ingreso, minuto_salida, clientes = 0;
    float pagos[MAX], ingresos_dia = 0, ingresos_mes = 0, total;
    char es_domingo, continuar = 's';
    
    while (continuar == 's' || continuar == 'S'){ // Bucle para ingresar datos de los clientes
        if (clientes >= MAX){ 
            printf("Se ha alcanzado el numero maximo de clientes del dia.\n"); // Si se alcanza el maximo de clientes, se sale del bucle    
            break;
        }

        int i = 0;
        while (i == 0){ 
            printf("Ingrese la hora de ingreso al estacionado(solo la hora, 6-22): "); // Preguntar hora de ingreso
            scanf("%d", &hora_ingreso);
            if (hora_ingreso < 6 || hora_ingreso > 22){ 
                printf("Hora invalida. Ingrese una hora entre 6 y 22: "); // Validar hora de ingreso
            }
            else {
                i=1;
            }
        }

        while (i == 1){ 
            printf("Ingrese el minuto de ingreso al estacionamiento: "); // Preguntar minuto de ingreso
            scanf("%d", &minuto_ingreso);
            if (minuto_ingreso < 0 || minuto_ingreso > 60){ 
                printf("Minuto invalido. Ingrese un minuto entre 0 y 60: "); // Validar minuto de ingreso
            }
            else {
                i=2;
            }
        }

        while (i == 2){ 
            printf("Ingrese la hora de salida al estacionado(solo la hora, 6-22): "); // Preguntar hora de salida
            scanf("%d", &hora_salida);
            if (hora_salida < 6 || hora_salida > 22){ 
                printf("Hora invalida. Ingrese una hora entre 6 y 22: "); // Validar hora de salida
            }
            else {
                i=3;
            }
        }
        while (i == 3){ 
            printf("Ingrese el minuto de salida al estacionamiento: "); // Preguntar minuto de salida
            scanf("%d", &minuto_salida);
            if (minuto_salida < 0 || minuto_salida > 60){ 
                printf("Minuto invalido. Ingrese un minuto entre 0 y 60: "); // Validar minuto de salida
            }
            else {
                i=4;
            }
        }

        // Preguntar si es domingo
        printf("¿Es domingo? (s/n): ");
        scanf(" %c", &es_domingo);

        // Cálculo del costo
        horas[clientes] = hora_salida - hora_ingreso; 
        minutos[clientes] = minuto_salida - minuto_ingreso; 
        if (minutos[clientes] < 0) { // Si los minutos son negativos, restar una hora y sumar 60 minutos
            minutos[clientes] += 60;
            horas[clientes]--;
        }

        if (horas[clientes] == 0 && minutos[clientes] <= 10){ // Si el tiempo es menor o igual a 10 minutos, no se cobra
            total = 0;
        }
        else if (horas[clientes] == 0 && minutos[clientes] <= 25){ // Si el tiempo es menor o igual a 25 minutos, se cobra 3 dolares
            total = 3;
        }
        else if (horas[clientes] == 0){ // Si el tiempo es menor o igual a 60 minutos, se cobra 5 dolares
            total = 10;
        }
        else {
            total = 10 + (horas[clientes] * 5); // Se cobra 10 dolares por la primera hora y 5 dolares por cada hora adicional
        }

        if (es_domingo == 's' || es_domingo == 'S') { // Si es domingo, se aplica un descuento del 20%
            total *= 0.8;
        }

        pagos[clientes] = total; 
        ingresos_mes += total;
        ingresos_dia += total;

        clientes++;

        printf("¿Desea ingresar otro cliente? (s/n): "); // Preguntar si desea ingresar otro cliente
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