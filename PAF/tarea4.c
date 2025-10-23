/* Gonzalo Fuenzalida
   Fecha: 02-09-25
   Tema: Matriz
*/ 

#define P 5

#include <stdio.h> 
#include <string.h> 

void recorrer_fila(char m[P][P], char palabra[]);
void recorrer_columna(char m[P][P], char palabra[]);
void recorrer_diagonal(char m[P][P], char palabra[]);
void inicializar(char m[P][P]);
void palabras(char m[P][P]);
void buscar_palabra(char m[P][P], char palabra[]);

int main(){
    char sopa_letras[P][P];
    inicializar(sopa_letras);
    palabras(sopa_letras);
    return 0;
}

void inicializar(char sopa_letras[P][P]){
    // Inicializamos la matriz con palabras predefinidas
    char copia [P][P] = {
        {'C', 'R', 'O', 'N', 'O'},
        {'A', 'A', 'S', 'O', 'L'},
        {'S', 'T', 'L', 'T', 'A'},
        {'A', 'O', 'L', 'A', 'R'},
        {'S', 'S', 'E', 'R', 'S'}
    };
    for (int i = 0; i < P; i++){
        for (int j = 0; j < P; j++){
            sopa_letras[i][j] = copia[i][j];
        }
    }
}

void palabras(char sopa_letras[P][P]){
    // Definir las palabras a buscar
    char *palabra[] = {"CASA", "RATOS", "CALAS", "LOSA", "RATON", "SOLO", "SALA"};
    for (int i = 0; i < 7; i++){
        buscar_palabra(sopa_letras, palabra[i]);
    }
}

void buscar_palabra(char sopa_letras[P][P], char palabra[]){
    recorrer_fila(sopa_letras, palabra);
    recorrer_columna(sopa_letras, palabra);
    recorrer_diagonal(sopa_letras, palabra);
}

void recorrer_fila(char sopa_letras[P][P], char palabra[]){
    int i, j, largo = strlen(palabra), k = 0;
    char reverso[largo + 1]; // Para almacenar la palabra invertida

    // Invertir la palabra
    for (int l = 0; l < largo; l++) {
        reverso[l] = palabra[largo - 1 - l];
    }
    reverso[largo] = '\0';

    // Recorrer las filas
    for (i = 0; i < P; i++){
        for (j = 0; j <= P - largo; j++){
            
            if (strncmp(&sopa_letras[i][j], palabra, largo) == 0){
                printf("Coincidencia normal en fila %d desde columna %d: ", i, j);
                for (k = 0; k < largo; k++){
                    printf("(%c = (%d,%d)) ", sopa_letras[i][j + k], i, (j + k));
                }
                printf("\n");
            }

            if (strncmp(&sopa_letras[i][j], reverso, largo) == 0){
                printf("Coincidencia en reverso en fila %d desde columna %d: ", i, j);
                for (k = 0; k < largo; k++){
                    printf("(%c = (%d,%d)) ", sopa_letras[i][j + k], i, (j + k));
                }
                printf("\n");
            }
        }
    }
}

void recorrer_columna(char sopa_letras[P][P], char palabra[]) {
    int i, j, largo = strlen(palabra), k;
    char reverso[largo + 1];

    // Invertir la palabra
    for (int l = 0; l < largo; l++) {
        reverso[l] = palabra[largo - 1 - l];
    }
    reverso[largo] = '\0';

    // Recorrer las columnas
    for (j = 0; j < P; j++) {
        for (i = 0; i <= P - largo; i++) {

            int igual = 1;
            for (k = 0; k < largo; k++) {
                if (sopa_letras[i + k][j] != palabra[k]) {
                    igual = 0;
                    break;
                }
            }
            if (igual) {
                printf("Coincidencia normal en columna %d desde fila %d: ", j, i);
                for (k = 0; k < largo; k++) {
                    printf("(%c = (%d,%d)) ", sopa_letras[i + k][j], (i + k), j);
                }
                printf("\n");
            }

            // Comparar la palabra en reverso
            igual = 1;
            for (k = 0; k < largo; k++) {
                if (sopa_letras[i + k][j] != reverso[k]) {
                    igual = 0;
                    break;
                }
            }
            if (igual) {
                printf("Coincidencia en reverso en columna %d desde fila %d: ", j, i);
                for (k = 0; k < largo; k++) {
                    printf("(%c = (%d,%d)) ", sopa_letras[i + k][j], (i + k), j);
                }
                printf("\n");
            }
        }
    }
}

void recorrer_diagonal(char sopa_letras[P][P], char palabra[]) {
    int i, j, largo = strlen(palabra), k;
    char reverso[largo + 1];

    // Invertir la palabra
    for (int l = 0; l < largo; l++) {
        reverso[l] = palabra[largo - 1 - l];
    }
    reverso[largo] = '\0';

    // Recorrer las diagonales principales
    for (i = 0; i <= P - largo; i++) {
        for (j = 0; j <= P - largo; j++) {

            int igual = 1;
            for (k = 0; k < largo; k++) {
                if (sopa_letras[i + k][j + k] != palabra[k]) {
                    igual = 0;
                    break;
                }
            }
            if (igual) {
                printf("Coincidencia normal en diagonal desde (%d,%d): ", i, j);
                for (k = 0; k < largo; k++) {
                    printf("(%c = (%d,%d)) ", sopa_letras[i + k][j + k], (i + k), (j + k));
                }
                printf("\n");
            }

            // Comparar la palabra en reverso en diagonal
            igual = 1;
            for (k = 0; k < largo; k++) {
                if (sopa_letras[i + k][j + k] != reverso[k]) {
                    igual = 0;
                    break;
                }
            }
            if (igual) {
                printf("Coincidencia en reverso en diagonal desde (%d,%d): ", i, j);
                for (k = 0; k < largo; k++) {
                    printf("(%c = (%d,%d)) ", sopa_letras[i + k][j + k], (i + k), (j + k));
                }
                printf("\n");
            }
        }
    }
    for (i = largo - 1; i < P; i++) {
    for (j = 0; j <= P - largo; j++) {
        // Palabra normal
        int igual = 1;
        for (k = 0; k < largo; k++) {
            if (sopa_letras[i - k][j + k] != palabra[k]) {
                igual = 0;
                break;
            }
        }
        if (igual) {
            printf("Coincidencia normal en diagonal secundaria desde (%d,%d): ", i, j);
            for (k = 0; k < largo; k++) {
                printf("(%c = (%d,%d)) ", sopa_letras[i - k][j + k], (i - k), (j + k));
            }
            printf("\n");
        }
        // Palabra reversa
        igual = 1;
        for (k = 0; k < largo; k++) {
            if (sopa_letras[i - k][j + k] != reverso[k]) {
                igual = 0;
                break;
            }
        }
        if (igual) {
            printf("Coincidencia en reverso en diagonal secundaria desde (%d,%d): ", i, j);
           for (k = 0; k < largo; k++) {
                printf("(%c = (%d,%d)) ", sopa_letras[i - k][j + k], (i - k), (j + k));
            }
            printf("\n");
        }
    }
}