#include <stdio.h>
#include <string.h>

void lee_original(char *, int);
void inicializa_alfabeto(char *);
void codificar(char *, char *, char *, int);
void graba_mensaje(char *);

int main(){
    char original[100];
    char alfabeto[100];
    char codificado[100];
    int n;

    //lee_original(original, n);
    inicializa_alfabeto(alfabeto);
    //codificar(original, codificado, alfabeto, n);
    //graba_mensaje(codificado);
    return 0;
}

void lee_original(char *original, int n){
    int i = 0, resultado = 0;

    FILE *file = fopen("original.txt", "r");
    fgets(original, 100, file);
    fclose(file);
    //printf("Mensaje original:%s\n", original);

    while (original[i] >= '0' && original[i] <= '9') {
        resultado = resultado * 10 + (original[i] - '0');
        i++;
    }
    printf("Numero n: %d\n", resultado);
}

void inicializa_alfabeto(char *alfabeto){
    int i;
    for (i = 0; i < 26; i++) {
        alfabeto[i] = 'A' + i;
        printf("Numero: %d %c \n", i, alfabeto[i]);
    }
    alfabeto[26] = ' ';
    for (i = 27; i < 37; i++) {
        alfabeto[i] = '0' + (i - 27);
        printf("Numero: %d %c \n", i, alfabeto[i]);
    }

    for (i = 37; i < 47; i++) {
        alfabeto;
    }

}