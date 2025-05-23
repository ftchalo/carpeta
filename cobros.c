#include <stdio.h>

#define MAX 100

int main() {
    int horas[MAX];
    int minutos[MAX];
    float pagos[MAX];
    char es_domingo, continuar = 's';
    int total_clientes = 0;

    float ingresos_dia = 0;
    float ingresos_mes = 0;

    while (continuar == 's' || continuar == 'S') {
        if (total_clientes >= MAX) {
            printf("Se ha alcanzado el número máximo de clientes del día.\n");
            break;
        }
        printf("Ingrese las horas que estuvo estacionado: ");
        scanf("%d", &horas[total_clientes]);

        printf("Ingrese los minutos adicionales: ");
        scanf("%d", &minutos[total_clientes]);

        printf("¿Es domingo? (s/n): ");
        scanf(" %c", &es_domingo); // Espacio antes del %c

        // Cálculo del costo
        float total = 0;
        int horas_cliente = horas[total_clientes];
        int minutos_cliente = minutos[total_clientes];

        if (horas_cliente == 0 && minutos_cliente <= 10) {
            total = 0;
        } else if (horas_cliente == 0 && minutos_cliente <= 25) {
            total = 3;
        } else if (horas_cliente == 0) {
            total = 10;
        } else {
            total = 10 + (horas_cliente - 1) * 5;
            if (minutos_cliente > 0) {
                total += 5;
            }
        }

        // Descuento si es domingo
        if (es_domingo == 's' || es_domingo == 'S') {
            total *= 0.9;
        }

        pagos[total_clientes] = total;

        ingresos_dia += total;
        ingresos_mes += total;

        total_clientes++;

        printf("¿Desea ingresar otro cliente? (s/n): ");
        scanf(" %c", &continuar);

    } 
    // Imprimir tabla diaria
    printf("\n-------------------------------\n");
    printf("Horas/min     | $ a pagar\n");
    printf("-------------------------------\n");
    for (int i = 0; i < total_clientes; i++) {
        printf("%2d h %2d min   | $%.2f\n", horas[i], minutos[i], pagos[i]);
    }
    // Mostrar resumen
    printf("-------------------------------\n");
    printf("Total ingresado hoy: $%.2f\n", ingresos_dia);
    printf("Histórico del mes:  $%.2f\n", ingresos_mes);

    return 0;
}
