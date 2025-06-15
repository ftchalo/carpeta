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
        arch = fopen("tatata/arreglo.txt", "r");
    }
    if (arch == NULL) {
        printf("Error al abrir el archivo.\n");
    } else {
        while (fscanf(arch, "%d", &num[n]) == 1 && n < MAX) {
            printf ("%d\n", num[n]);
            n++;
        }
        fclose(arch);
    }
    return n;
}

void buscar_repetidos(int n) {
    int unicos[MAX];
    int contador[MAX];
    int total_unicos = 0;

    for (int i = 0; i < MAX; i++) {
        contador[i] = 0;
    }

    printf("-------------------------------\n");

    for (int i = 0; i < n; i++) {
        int indice = -1;
        for (int j = 0; j < total_unicos; j++) {
            if (unicos[j] == num[i]) {
                indice = j;
                break;
            }
        }

        if (indice == -1) {
            unicos[total_unicos] = num[i];
            contador[total_unicos] = 1;
            total_unicos++;
        } else {
            contador[indice]++;
        }
    }

    for (int i = 0; i < total_unicos; i++) {
        if (contador[i] > 1) {
            printf("El numero %d esta repetido %d veces.\n", unicos[i], contador[i]);
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

