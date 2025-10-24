/*
 -Autores: Gonzalo Fuenzalida, Ignacio Ávila
 -Fecha: 22-10-2025
 -Fecha de entrega: 26-10-2025
 -Tema: El solitario
 */ 
#include <stdio.h>

#define N 7
#define FICHA 'X'
#define VACIO ' '
#define INVALIDA 'O'
#define MAX_MOVIMIENTOS 33

typedef struct juego {
    char tablero[N][N];
    //variables temporales
    int start_fila;
    int start_col;
    int fin_fila;
    int fin_col;
    //variables de control para la solución
    int sol_start_fila[MAX_MOVIMIENTOS];
    int sol_start_col[MAX_MOVIMIENTOS];
    int sol_fin_fila[MAX_MOVIMIENTOS];
    int sol_fin_col[MAX_MOVIMIENTOS];
    int mov_realizados;
}JUEGO;

void leer_solitario(JUEGO *juego);
int objetivo(JUEGO *juego);
int bus_solu(JUEGO *juego, int can_saltos);
void print_solu(JUEGO *juego);
int ubi_juego(JUEGO *juego);
int contador_fichas(JUEGO *juego);

int main() {
    JUEGO juego;
    leer_solitario(&juego);
    print_solu(&juego);
    return 0;
}

void leer_solitario(JUEGO *juego) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%c", &juego->tablero[i][j]);
            if (juego->tablero[i][j] == '\n') {
                j--;
            }
        }

    }
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%c", juego->tablero[i][j]);
        }
        printf("\n");
    }   
}

int objetivo(JUEGO *j) {
    if (contador_fichas(j) != 1) return 0;
    return j->tablero[3][3] == FICHA;
}

int contador_fichas(JUEGO *j) {
    int i, k, c = 0;
    for (i = 0; i < N; i++) {
        for (k = 0; k < N; k++) {
            if (j->tablero[i][k] == FICHA) {
                c++;
            }
        }
    }
    return c; 
}

int bus_solu(JUEGO *j, int can_saltos) {
    if (objetivo(j)) {
        j->mov_realizados = can_saltos;
        return 1;
    }
    int r, c, k;
    int dir_filas[] = {-1, 1, 0, 0};
    int dir_cols[]  = {0, 0, -1, 1};

    for (r = 0; r < N; r++) {
        for (c = 0; c < N; c++) {
            if (j->tablero[r][c] != FICHA) continue;
            for (k = 0; k < 4; k++) {
                int fila_salto = r + dir_filas[k];
                int col_salto = c + dir_cols[k];
                int fila_dest = r + 2 * dir_filas[k];
                int col_dest = c + 2 * dir_cols[k];

                if (fila_salto < 0 || fila_salto >= N || col_salto < 0 || col_salto >= N ||
                    fila_dest < 0 || fila_dest >= N || col_dest < 0 || col_dest >= N)continue;

                if (j->tablero[fila_salto][col_salto] == FICHA && j->tablero[fila_dest][col_dest] == VACIO) {
                    j->tablero[r][c] = VACIO;
                    j->tablero[fila_salto][col_salto] = VACIO;
                    j->tablero[fila_dest][col_dest] = FICHA;

                    if (bus_solu(j, can_saltos + 1)) {
                        if (can_saltos < MAX_MOVIMIENTOS) {
                            j->sol_start_fila[can_saltos] = r + 1;
                            j->sol_start_col[can_saltos] = c + 1;
                            j->sol_fin_fila[can_saltos] = fila_dest + 1;
                            j->sol_fin_col[can_saltos] = col_dest + 1;
                        }
                        return 1;
                    }

                    j->tablero[r][c] = FICHA;
                    j->tablero[fila_salto][col_salto] = FICHA;
                    j->tablero[fila_dest][col_dest] = VACIO;
                }
            }
        }
    }
    return 0; //en caso de que no haya solucion por este sector
}

void print_solu(JUEGO *j) {
    int i, k, r;
    
    if (bus_solu(j, 0)) {
        printf("Solucion encontrada en %d movimientos:\n", j->mov_realizados);
        for (i = 0; i < j->mov_realizados; i++) {
            printf("%d: posicion <%d,%d> a posicion <%d,%d>\n", i + 1,
                   j->sol_start_fila[i], j->sol_start_col[i],
                   j->sol_fin_fila[i], j->sol_fin_col[i]);
        }
    } 
}