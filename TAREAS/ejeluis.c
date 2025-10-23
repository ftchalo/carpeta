#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINEA 125
#define ARCHIVO_ENTRADA "archivo1.txt"
#define ARCHIVO_SALIDA "estadisticas.txt"

/* Función para contar palabras en una línea */
int contar_palabras_linea(const char *linea) {
    int contador = 0;
    int en_palabra = 0;
    int i = 0;
    
    while (linea[i] != '\0') {
        /* Si es carácter alfabético y no estamos en palabra */
        if (isalpha(linea[i]) && !en_palabra) {
            contador++;
            en_palabra = 1;
        }
        /* Si no es alfabético, terminó la palabra */
        else if (!isalpha(linea[i])) {
            en_palabra = 0;
        }
        i++;
    }
    
    return contador;
}


void analizar_archivo() {
    FILE *entrada = NULL;
    FILE *salida = NULL;
    char linea[MAX_LINEA];
    int total_palabras = 0;
    int total_lineas = 0;
    
    /* Abrir archivo de entrada para lectura */
    entrada = fopen(ARCHIVO_ENTRADA, "r");
    if (entrada == NULL) {
        printf("Error: No se pudo abrir %s\n", ARCHIVO_ENTRADA);
        printf("Creando archivo de ejemplo...\n");
        
       
    }
    
    
    
    /* Leer línea por línea y contar palabras */
    while (fgets(linea, MAX_LINEA, entrada) != NULL) {
        total_palabras += contar_palabras_linea(linea);
        total_lineas++;
    }
    
    /* Cerrar archivo de entrada */
    fclose(entrada);
    
    /* Abrir archivo de salida para escribir resultados */
    salida = fopen(ARCHIVO_SALIDA, "w");
    if (salida == NULL) {
        printf("Error: No se pudo crear %s\n", ARCHIVO_SALIDA);
        return;
    }
    
    /* Escribir estadísticas en archivo de salida */
    fprintf(salida, "=== ESTADISTICAS DEL ANALISIS ===\n\n");
    fprintf(salida, "Archivo analizado: %s\n", ARCHIVO_ENTRADA);
    fprintf(salida, "Total de lineas: %d\n", total_lineas);
    fprintf(salida, "Total de palabras: %d\n", total_palabras);
    
    if (total_lineas > 0) {
        float promedio = (float)total_palabras / total_lineas;
        fprintf(salida, "Promedio de palabras por linea: %.2f\n", promedio);
    }
    
    fprintf(salida, "\n=== FIN DEL REPORTE ===\n");
    fclose(salida);
    
    /* Mostrar resultados en pantalla */
    printf("\nAnalisis completado!\n");
    printf("Lineas procesadas: %d\n", total_lineas);
    printf("Palabras contadas: %d\n", total_palabras);
    printf("Resultados en archivo de salida en: %s\n", ARCHIVO_SALIDA);
}

/* Función para mostrar contenido de archivo */
void mostrar_archivo(const char *nombre_archivo) {
    FILE *archivo = NULL;
    char linea[MAX_LINEA];
    
    archivo = fopen(nombre_archivo, "r");
    if (archivo == NULL) {
        printf("Error: No se pudo abrir %s\n", nombre_archivo);
        return;
    }
    
    printf("\n=== CONTENIDO DE %s ===\n", nombre_archivo);
    while (fgets(linea, MAX_LINEA, archivo) != NULL) {
        printf("%s", linea);
    }
    printf("=== FIN DEL ARCHIVO ===\n\n");
    
    fclose(archivo);
}


/* Programa principal */
int main() {
  
       
            /* Mostrar contenido del archivo original */
            mostrar_archivo(ARCHIVO_ENTRADA);
            analizar_archivo();
       
    
    return 0;
}