#include <stdio.h>

#define MAX 8
int separar_rut(int);
int multi(int[], int );

int main()  {  
    int rut, digito_verificador, rut_digitos[MAX];

    // Ingresar rut
    printf("Ingrese el rut sin digito verificador: ");
    scanf("%d", &rut);
    printf("Ingrese el digito verificador: ");
    scanf("%d", &digito_verificador);
    separar_rut(rut);
    multi(rut_digitos, MAX);

    return 0;
} 

int separar_rut(int rut) {
    int rut_digitos[MAX];
    for (int i = 0; i < MAX; i++) {
        
        rut_digitos[i] = rut % 10; // Extrae el último dígito
        rut /= 10; // Elimina el último dígito del rut
        printf("%d\n", rut_digitos[i]);
    } 
}

int multi(int rut_digitos[], int n) {
    int suma = 0, n = 2;
    for (int i = 0; i < 8; i++) {
        suma += rut_digitos[i] * (n + i);
        if (n == 7) {
            n = 2; // Reinicia el multiplicador a 2 después de llegar a 7
        } 
    }
    return suma;

}