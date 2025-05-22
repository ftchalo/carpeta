#include <stdio.h>

int main() {
  // Declaración de un arreglo de enteros (tabla)
  int tabla[5]; // Crea una tabla de 5 enteros

  // Asignación de valores a los elementos de la tabla
  tabla[0] = 10;
  tabla[1] = 20;
  tabla[2] = 30;
  tabla[3] = 40;
  tabla[4] = 50;

  // Acceso y uso de los elementos de la tabla
  printf("El valor en la posición 0 es: %d\n", tabla[0]);
  printf("El valor en la posición 2 es: %d\n", tabla[2]);

  return 0;
}