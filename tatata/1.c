#include <stdio.h>
#include <string.h>

int preguntar_numero (int);
void buscar_repetidos(int);
void imprimir_sin_repetidos(int);

int num[100];
#define MAX 100

int main () {
    int n = 0;
    n = preguntar_numero (n);
    buscar_repetidos( n);
    imprimir_sin_repetidos(n);
    return 0;
}

int preguntar_numero (int n) {
    FILE *arch;
    arch = fopen("arreglo.txt", "r");
    if (arch == NULL) {
        printf("Error al abrir el archivo.\n");
    }
    else {
        while (fscanf(arch, "%d", &num[n]) == 1 && n < MAX) {
            printf ("%d\n", num[n]);
            n++;
        }
    }
    fclose(arch);
    return n;
}

void buscar_repetidos(int n) {
    int hay_repetidos[MAX], j = 0, i = 0, contador[MAX];
    printf("-------------------------------\n");
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (num[i] == num[j]) {
                hay_repetidos[j] = num[i];
                
                contador[j]++;
            }

        }
    }
    for (j = 0; j < n; j++) {
        if (hay_repetidos[j]) {
            printf("El numero %d esta repetido  %d veces.\n", hay_repetidos[j], contador);
        }
    }
}

void imprimir_sin_repetidos(int n) {
    printf("-------------------------------\n");
    printf("Numeros sin repetir:\n");
    for (int i = 0; i < n; i++) {
        int ya_impreso = 0;
        for (int j = 0; j < i; j++) { // Solo hasta i-1
            if (num[i] == num[j]) {
                ya_impreso = 1;
                break;
            }
        }
        if (ya_impreso == 0) {
            printf("%d\n", num[i]);
        }
    }
}

