#include <stdio.h>

int main() {
    float suma = 0, cantidad = 0, nota, promedio, mayor, menor, aritmetica, suma_total = 0;
    printf("Escribe 0 cuando termines de ingresar las notas");
    while (1) {  //bucle infinito
        printf("Escribe un número: ");
        scanf("%f", & nota); //leer nota
        if (nota == 0) {
            break; // Salir del bucle si se ingresa 0
        }
        if (nota > 0 && nota <= 7) { //validar nota
            printf("Nota valida\n"); //mesaje de nota valida 
            printf("La nota es %f\n", nota);
            suma = suma + nota; //sumar 1 a la cantidad de notas totales
         if (nota > mayor) {
            mayor = nota; //nota mayor
        }
          if (nota < menor && nota > 0){
            menor = nota; //nota menor
          }
          cantidad++; //suamr uno a la cantidad de notas totales
        }
         else if (nota > 7) {
            printf("Nota invalida. Debe ser numeros entre 1 y 7\n"); //mensaje de error
        }
         else if (nota < 0) {
            printf("Nota invalida. Debe ser numeros entre 1 y 7\n"); //mensaje de error
        }  
    }
    promedio = suma / cantidad; //calcular promedio
    suma_total = suma_total + (nota - promedio) * (nota - promedio); 
    printf("El promedio es %f", promedio);
    printf("La nota más grande es %f", mayor);
    printf("La nota más chica es %f", menor);
    
    return 0; //salir del programa
}
