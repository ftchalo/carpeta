/*
 * autores: Gonzalo Fuenzalida Pérez, Vicente González
 * Sección 2 INF
 * Programa decodificador: invierte las dos etapas de codificación para restaurar el mensaje original
 */
#include <stdio.h>
#include <string.h>

void lee_codificado(char *, int *);
void inicializa_alfabeto(char *);
void decodificar(char *, char *, char *, int);
void segunda_etapa_inversa(char *, char *, int);
void primera_etapa_inversa(char *, char *, int);
void graba_decodificado(char *);

int main() {
    char codificado[200];
    char alfabeto[48];
    char decodificado[200];
    int N;

    lee_codificado(codificado, &N);
    inicializa_alfabeto(alfabeto);
    decodificar(codificado, decodificado, alfabeto, N);
    graba_decodificado(decodificado);
    return 0;
}

// Lee el mensaje codificado y extrae el valor N (prefijo numérico)
void lee_codificado(char *codificado, int *n) {
    int i = 0;
    *n = 0;
    FILE *file = fopen("codificado.txt", "r");
    if (!file) {
        printf("Error al abrir codificado.txt\n");
        return;
    }
    if (!fgets(codificado, 200, file)) {
        fclose(file);
        return;
    }
    fclose(file);
    codificado[strcspn(codificado, "\n")] = '\0';
    // Construye N hasta encontrar '#'
    while (codificado[i] >= '0' && codificado[i] <= '9') {
        *n = (*n) * 10 + (codificado[i] - '0');
        i++;
    }
}

// Inicializa el alfabeto usado para codificación/decodificación
void inicializa_alfabeto(char *alfabeto) {
    int i;
    for (i = 0; i < 26; i++) alfabeto[i] = 'A' + i;
    alfabeto[26] = ' ';
    for (i = 27; i < 37; i++) alfabeto[i] = '0' + (i - 27);
    alfabeto[37] = '!';
    alfabeto[38] = ',';
    alfabeto[39] = '.';
    alfabeto[40] = ':';
    alfabeto[41] = ';';
    alfabeto[42] = '?';
    alfabeto[43] = '-';
    alfabeto[44] = '+';
    alfabeto[45] = '*';
    alfabeto[46] = '/';
    alfabeto[47] = '\0';
}

// Invierte ambas etapas de codificación
void decodificar(char *codificado, char *decodificado, char *alfabeto, int n) {
    int i = 0;
    // Copia mensaje tras el '#'
    while (codificado[i] != '#' && codificado[i] != '\0') i++;
    if (codificado[i] == '#') i++;
    strcpy(decodificado, codificado + i);
    // Ajusta k como N mod tamaño del alfabeto
    int k = n % 47;
    segunda_etapa_inversa(decodificado, alfabeto, k);
    primera_etapa_inversa(decodificado, alfabeto, k);
}

// Invierte la segunda etapa (solo posiciones con índice par en el alfabeto)
void segunda_etapa_inversa(char *texto, char *alfabeto, int k) {
    int i, j, z;
    for (i = 0; texto[i] != '\0'; i++) {
        for (j = 0; j < 47; j++) {
            if (texto[i] == alfabeto[j] && (j % 2 == 0)) {
                z = j + k;
                while (z > 46) z -= 47;
                texto[i] = alfabeto[z];
                break;
            }
        }
    }
}

// Invierte la primera etapa (todas las posiciones)
void primera_etapa_inversa(char *texto, char *alfabeto, int k) {
    int i, j, z;
    for (i = 0; texto[i] != '\0'; i++) {
        for (j = 0; j < 47; j++) {
            if (texto[i] == alfabeto[j]) {
                z = j + k;
                while (z > 46) z -= 47;
                texto[i] = alfabeto[z];
                break;
            }
        }
    }
}

// Graba el mensaje decodificado en "decodificado.txt"
void graba_decodificado(char *decodificado) {
    FILE *file = fopen("decodificado.txt", "w");
    if (!file) {
        printf("Error al crear decodificado.txt\n");
        return;
    }
    fputs(decodificado, file);
    printf("Mensaje decodificado: %s\n", decodificado);
    fclose(file);
}