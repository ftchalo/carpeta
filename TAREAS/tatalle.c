#include <stdio.h>

int main(void) {
    int i;
    char c;
    /* Encabezados de columnas */
    printf(" Dec | Hex  | Char\n");
    printf("-----+------+-----\n");

    /* Recorremos los códigos ASCII del 0 al 127 */
    for (i = 33; i < 128; i++) {
        /* Imprimible si está entre 32 (espacio) y 126 (~) */
        c = (i >= 33 && i <= 126) ? i : '.';
        printf("%4d | 0x%02X |   %c\n", i, i, c);
    }

    return 0;
}