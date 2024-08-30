// Autor: Thiago Queiroz - 1 Questao - Dia: 30/08/2024 Horario: 11:23

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char base2[100];
char baseoctal[100];
char basehexa[100];
char codigobcd[400];

void base10parabase2(int numero) {
    int i = 0;
    if (numero < 0) {
        printf("Essa operacao nao suporta numeros negativos.\n");
        return;
    }
    printf("Conversao do numero decimal %d para base 2:\n", numero);
    while (numero > 0) {
        int resto = numero % 2;
        printf("%d / 2 tem resto: %d\n", numero, resto);
        base2[i] = resto + '0';
        numero = numero / 2;
        i++;
    }
    base2[i] = '\0';
    strrev(base2);
    printf("O total e: %s\n", base2);
}

void base10parabase8(int numero) {
    int i = 0;
    if (numero < 0) {
        printf("Essa operacao nao suporta numeros negativos.\n");
        return;
    }
    printf("Conversao do numero decimal %d para base 8:\n", numero);
    while (numero > 0) {
        int resto = numero % 8;
        printf("%d / 8 tem resto: %d\n", numero, resto);
        baseoctal[i] = resto + '0';
        numero = numero / 8;
        i++;
    }
    baseoctal[i] = '\0';
    strrev(baseoctal);
    printf("O total e: %s\n", baseoctal);
}

void base10parabase16(int numero) {
    int i = 0;
    if (numero < 0) {
        printf("Essa operacao nao suporta numeros negativos.\n");
        return;
    }
    printf("Conversao do numero decimal %d para base 16:\n", numero);
    while (numero > 0) {
        int resto = numero % 16;
        if (resto < 10) {
            printf("%d / 16 tem resto: %d\n", numero, resto);
            basehexa[i] = resto + '0';
        } else {
            printf("%d / 16 tem resto: %d\n", numero, resto);
            basehexa[i] = resto + 55;
        }
        numero = numero / 16;
        i++;
    }
    basehexa[i] = '\0';
    strrev(basehexa);
    printf("O total e: %s\n", basehexa);
}

void base10parabaseBCD(int numero) {
    int i = 0;
    codigobcd[0] = '\0';
    if (numero < 0) {
        printf("Essa operacao nao suporta numeros negativos.\n");
        return;
    }
    printf("Conversao do numero decimal %d para BCD:\n", numero);
    char temp[400] = "";
    while (numero > 0) {
        int digito = numero % 10;
        char bcd[5];
        
        switch(digito) {
            case 0: strcpy(bcd, "0000"); break;
            case 1: strcpy(bcd, "0001"); break;
            case 2: strcpy(bcd, "0010"); break;
            case 3: strcpy(bcd, "0011"); break;
            case 4: strcpy(bcd, "0100"); break;
            case 5: strcpy(bcd, "0101"); break;
            case 6: strcpy(bcd, "0110"); break;
            case 7: strcpy(bcd, "0111"); break;
            case 8: strcpy(bcd, "1000"); break;
            case 9: strcpy(bcd, "1001"); break;
        }
        
        printf("%d em BCD: %s\n", digito, bcd);
        
        strcat(temp, bcd);
        numero = numero / 10;
    }
    
    int len = strlen(temp);
    for (int j = 0; j < len; j += 4) {
        strncat(codigobcd, &temp[len - j - 4], 4);
        strcat(codigobcd, " ");
    }
    
    codigobcd[strlen(codigobcd) - 1] = '\0';
    printf("O total e: %s\n", codigobcd);
}

int main() {
    int opcao;
    int numero;
    printf("=====================================\n");
    printf("Calculadora de Bases Numericas :D\n");
    printf("=====================================\n");
    printf("1. Decimal para Binario\n");
    printf("2. Decimal para Octal\n");
    printf("3. Decimal para Hexadecimal\n");
    printf("4. Decimal para BCD\n");
    printf("Digite o numero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Entrada invalida. Por favor insira um numero inteiro.\n");
        return 1;
    }
    printf("Digite a opcao desejada: ");
    if (scanf("%d", &opcao) != 1) {
        printf("Entrada invalida. Por favor insira um numero inteiro.\n");
        return 1;
    }
    
    switch (opcao) {
        case 1:
            base10parabase2(numero);
            break;
        case 2:
            base10parabase8(numero);
            break;
        case 3:
            base10parabase16(numero);
            break;
        case 4:
            base10parabaseBCD(numero);
            break;
        default:
            printf("Opcao invalida\n");
    }
    return 0;
}
