/*
 -Autores: Gonzalo Fuenzalida, Ignacio Ávila 
 -Fecha: 22-10-2025
 -Tema: El solitario 
 */ 

#include <stdio.h>
#include <string.h>

#define N 7
#define FICHA 'X'
#define VACIO ' '

void leer_solitario(char [N][N]);
void imprimir_solitario(char [N][N]);
int resolver(int, char[N][N]);
int movimiento(char[N][N], int, int);
int puede_moverse_(char[N][N], int, int);


int main(){
    int n_movimientos = 0;
    char solitario[N][N];
    leer_solitario(solitario);
    imprimir_solitario(solitario);
    resolver(n_movimientos, solitario);

    return 0;
}

void leer_solitario(char solitario[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            scanf("%c", &solitario[i][j]);
            if(solitario[i][j] == '\n'){
                j--;
            }
        }
    }
}

void imprimir_solitario(char solitario[N][N]){
    int i, j;
    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            printf("%c", solitario[i][j]);
        }
        printf("\n");
    }
}

int resolver(int n_movimientos, char solitario[N][N]){
    int i, j, k, si, sj, ni, nj;
    int di[4] = {0, 0, 1, -1};
    int dj[4] = {1, -1, 0, 0};

    for (i = 0; i < N; i++){
        for (j = 0; j < N; j++){
            if (solitario[i][j] == FICHA){
                for (k = 0; k < 4; k++){
                    ni = i + di[k]; nj = j + dj[k];
                    si = i + 2*di[k]; sj = j + 2*dj[k];

                    // comprobar límites
                    if (ni < 0 || ni >= N || nj < 0 || nj >= N) continue;
                    if (si < 0 || si >= N || sj < 0 || sj >= N) continue;

                    // comprobaciones de movimiento: vecino 'X' y destino ' ' (vacío)
                    if (solitario[ni][nj] == FICHA && solitario[si][sj] == VACIO){
                        // realizar movimiento
                        solitario[i][j] = VACIO;
                        solitario[ni][nj] = VACIO;
                        solitario[si][sj] = FICHA;

                        if (resolver(n_movimientos + 1, solitario)) {
                            printf("%d: posicion <%d,%d> a posicion <%d,%d>\n", n_movimientos + 1, i + 1, j + 1, si + 1, sj + 1);
                            return 1;
                        }

                        // deshacer movimiento
                        solitario[i][j] = FICHA;
                        solitario[ni][nj] = FICHA;
                        solitario[si][sj] = VACIO;
                    }
                }
            }
        }
    }
    return 0;
}

int movimiento(char solitario[N][N], int i, int j){
    solitario[i][j] = 'O';
    solitario[i][j + 1] = 'O';
    solitario[i][j + 2] = FICHA;

    return 0;
}

int puede_moverse_(char solitario[N][N], int x, int y){
    if (solitario[x][y] == 'O' && solitario[x][y + 1] == 'O' && solitario[x][y + 2] == 'X'){
                    movimiento(solitario, x, y);
                    return 1;
                }
    return 0;
}
