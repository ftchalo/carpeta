#include <stdio.h>

int main() {
    float numero, end, nota, promedio, mayor, menor, aritmetica;
    int suma;
    
    int cantidad;
    int i;
    suma= 0;
     cantidad = 0;
    i=0;
    printf("Escribe 0 cuando termines de ingresar las notas");
    while (i < 1) {
        scanf("%f",&nota);
        if (nota>0 && nota<=7) {

         printf("la nota es %f", nota);
         suma= suma + nota;
         if (nota > mayor) {
            mayor=nota;
         }
          if (nota < menor && nota > 0){
            menor= nota;
          }
        
          cantidad++;
        promedio= suma/cantidad;
          if (nota == 0){
            int i=1;
           }

        }
    
    }
     printf("Ingresa nota par la desviación estándar");
        scanf("%f",&nota);
        aritmetica=( (promedio - nota)*(promedio - nota)/cantidad);
        aritmetica = sqrt(2);
        printf("El promedio es %f", promedio);
        printf("La nota más grande es %f", mayor);
        printf("La nota más chica es %f", menor);

}