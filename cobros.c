#include <stdio.h>

int main() {
    int hora_ingreso, minuto_ingreso, deuda = 0, domingo, hora_salida, minuto_salida, estadia_horas, estadia_minutos, minutos_total;
    while (0){
        
        printf("hora de ingreso (debe de ingresar las hora y los minutos de ingreso por separado)");
        scanf("%d", &hora_ingreso);
        printf("minuto en el cual ingreso");
        scanf( "%d", &minuto_ingreso);

        printf("hora de salida (debe de ingresar las hora y los minutos de ingreso por separado)");
        scanf("%d", &hora_salida);
        printf("minuto en el cual salio");
        scanf("%d", &minuto_salida);

        estadia_horas = hora_salida - hora_ingreso;
        estadia_horas = estadia_horas / 60;
        estadia_minutos = minuto_salida - minuto_ingreso;
        if (estadia_minutos < 0){
            estadia_minutos = estadia_minutos * -1;
        }
        minutos_total = estadia_minutos + estadia_horas;
        printf ("es domingo? (0 para falso y 1 para verdadero)");
        scanf("%d", domingo);
        if (domingo == 1){
          deuda = deuda * 80;
          deuda = deuda / 100;
        }
        if (minutos_total < 0){
            printf("Como la estadia fue menor a 10m la deuda es 0");
        }       
    }
    return 0;
}