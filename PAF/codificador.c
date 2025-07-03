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
    //printf("n: %d\n", N);
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
    int i, j, z;
    int intercumunicador[100];

    for (i = 2; i < (strlen(original) + 2); i++) {
        for (j = 0; j < (strlen(alfabeto)); j++) {
            if (original[i] == alfabeto[j]) {
                intercumunicador[i] = alfabeto[j - n];
                
            }
        }
    }

    printf("Mensaje codificado: ");
    printf("%c", original[0]);
    printf("%c", original[1]);
    for (i = 2; i < (strlen(original) + 2); i++) {
        printf("%c", intercumunicador[i]);
    }
}