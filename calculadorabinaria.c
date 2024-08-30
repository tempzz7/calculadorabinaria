#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <math.h>

char base2[100];
char baseoctal[100];
char basehexa[100];
char codigobcd[100];

printf("=====================================\n");
printf("Calculadora de Bases Numéricas\n");
printf("=====================================\n");
printf("1. Decimal para Binário\n");
printf("2. Decimal para Octal\n");
printf("3. Decimal para Hexadecimal\n");
printf("4. Decimal para BCD\n");




void base10parabase2(int numero){
    int i = 0;
    while(numero > 0){
        base2[i] = numero % 2 + '0';
        numero = numero / 2;
        i++;
    }
    base2[i] = '\0';
}




