#include <stdio.h>
#include <string.h>

void lee_original(char *, int *);
void inicializa_alfabeto(char *);
void codificar(char *, char *, char *, int);
void graba_mensaje(char *);

int main(){
    char original[100];
    char alfabeto[100];
    char codificado[100];
    int N = 0;

    lee_original(original, &N);
    inicializa_alfabeto(alfabeto);
    codificar(original, codificado, alfabeto, N);
    //graba_mensaje(codificado);
    return 0;
}

void lee_original(char *original, int *n){
    int i = 0;

    FILE *file = fopen("original.txt", "r");
    fgets(original, 100, file);
    fclose(file);
    //printf("Mensaje original:%s\n", original);

    while (original[i] >= '0' && original[i] <= '9') { 
        *n = (*n) * 10 + (original[i] - '0');
        i++;
    }

    printf("Numero n: %d\n", *n);
}

void inicializa_alfabeto(char *alfabeto){
    int i;
    for (i = 0; i < 26; i++) {
        alfabeto[i] = 'A' + i;
        //printf("Numero: %d %c \n", i, alfabeto[i]);
    }
    alfabeto[26] = ' ';
    for (i = 27; i < 37; i++) {
        alfabeto[i] = '0' + (i - 27);
        //printf("Numero: %d %c \n", i, alfabeto[i]);
    }

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

}

void codificar(char *original, char *codificado, char *alfabeto, int n){


    int i = 0, j, z, k = n, contador = 0;

    while (original[i] >= '0' && original[i] <= '9') { 
        contador++;
        i++;
    }
    if (n> 47) {
        k = n % 47; // Asegura que n esté dentro del rango del alfabeto
    }
    //primera codificacion
    for (i = contador + 1; i < (strlen(original) + 2); i++) {
        for (j = 0; j < (strlen(alfabeto)); j++) {
            if (original[i] == alfabeto[j]) {
                z = j - k;
                while (z < 0) {
                    z = z + 47;
                }
                codificado[i] = alfabeto[z];
            }
        }
    }
    printf("Mensaje codificado: ");
    codificado[0] = n;
    codificado[1] = '#';
    printf("%d", n);
    for (i = 1; i < (strlen(original)); i++) {
        printf("%c", codificado[i]);
    }

    //segunda codificacion
    for (i = contador + 1; i < (strlen(codificado) + 2); i++) {
        for (j = 0; j < (strlen(alfabeto)); j++) {
            if (codificado[i] == alfabeto[j]) {
                if(j % 2 == 0){
                    z = j - k;
                    while (z < 0) {
                    z = z + 47;
                    }
                    codificado[i] = alfabeto[z];

                }
                
                
            }
        }
    }
    
    printf("\nMensaje codificado segunda vez: ");
    printf("%d", n);
        for (i = 1; i < (strlen(original)); i++) {
        printf("%c", codificado[i]);
    }

    
}