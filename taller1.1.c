#include <stdio.h>

int main() {
    float suma = 0, cantidad = 0, promedio, mayor = 0, menor = 7, aritmetica, suma_total = 0, suma_diferencias, desviacion, d;
    int i, nota;
    float notas[100];
    printf("\nEscribe 0 cuando termines de ingresar las notas\n\n");
    while (1) {  //bucle infinito
        printf("\nEscribe un numero: ");
        scanf("%d", & nota); //leer nota
        if (nota == 0) {
            break; // Salir del bucle si se ingresa 0
        }
        if (nota > 0 && nota <= 7) { //validar nota
            printf("\nNota valida\n"); //mesaje de nota valida 
            printf("\nLa nota es %d\n", nota);
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
            printf("\nNota invalida. Debe ser numeros entre 1 y 7\n"); //mensaje de error
        }
         else if (nota < 0 ) {
            printf("\nNota invalida. Debe ser numeros entre 1 y 7\n"); //mensaje de error
        }  
        if ( cantidad >= 100) {
            printf("\nse ha llegado al maximo de notas\n"); //mensaje de error
        }
    }
    promedio = suma / cantidad; //calcular promedio
    for(i = 0; i < cantidad; i++){
        suma_diferencias += (notas[i] - promedio) * (notas[i] - promedio);
    }
    desviacion = suma_diferencias / cantidad;
    d = 0;
    while (d* d < desviacion) {
        d = d + 0.000001;
    }
    printf("\nEl promedio es %f\n", promedio);
    printf("\nLa nota mas grande es %f\n", mayor);
    printf("\nLa nota mas chica es %f\n", menor);
    printf ("\nLa desviacion estandar es %f\n", d);
    return 0; //salir del programa
}
