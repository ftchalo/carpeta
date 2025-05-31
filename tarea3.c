#include <stdio.h>

#define MAX 8
void separar_rut(int rut, int rut_digitos[]);
void ingresar_datos(int rut_digitos[], int *digito_verificador);
char calcular_dv(int rut_digitos[]);

int main()  {  
    int rut_digitos[MAX];
    int digito_verificador;

    ingresar_datos(rut_digitos, &digito_verificador);

    char dv_calculado = calcular_dv(rut_digitos);

    printf("Digito verificador calculado: %c\n", dv_calculado);
    printf("Digito verificador ingresado: %d\n", digito_verificador);

    if ((dv_calculado == 'K' && (digito_verificador == 10)) ||
        (dv_calculado == '0' && (digito_verificador == 0)) ||
        (dv_calculado >= '0' && dv_calculado <= '9' && dv_calculado - '0' == digito_verificador)) {
        printf("El digito verificador es correcto.\n");
    } else {
        printf("El digito verificador es incorrecto.\n");
    }

    return 0;
} 

void ingresar_datos(int rut_digitos[], int *digito_verificador) {
    int rut;
    printf("Ingrese el rut sin digito verificador: ");
    scanf("%d", &rut);
    printf("Ingrese el digito verificador (0-9, para K use 10): ");
    scanf("%d", digito_verificador);

    separar_rut(rut, rut_digitos);
}

void separar_rut(int rut, int rut_digitos[]) {
    for (int i = 0; i < MAX; i++) {
        rut_digitos[i] = rut % 10;
        rut /= 10;
    } 
}

char calcular_dv(int rut_digitos[]) {
    int suma = 0;
    int n = 2;
    for (int i = 0; i < MAX; i++) {
        suma += rut_digitos[i] * n;
        n++;
        if (n > 7) {
            n = 2;   
        } 
    }
    int resto;
    resto = 11 - (suma % 11);
    if (resto == 11){
      return '0';  
    } 
    if (resto == 10) {
       return 'K'; 
    } 
    return resto + '0';
}