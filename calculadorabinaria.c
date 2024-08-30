// Autor: Thiago Queiroz - 1 Questao - Dia: 30/08/2024 Horario: 11:24
// Autor: Thiago Queiroz - 2 Questão - Dia: 30/08/2024 Horario: 12:32
// Autor: Thiago Queiroz - 3 Questão - Dia: 30/08/2024 Horario: 14:25

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char base2[100];
char baseoctal[100];
char basehexa[100];
char codigobcd[400];
char base16bits[17]; 

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
            basehexa[i] = resto + 55; // 'A' - 10 = 65 - 10 = 55
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

void base10paraBase16bits(int numero) {
    char temp16bits[17];
    memset(temp16bits, '0', sizeof(temp16bits) - 1);
    temp16bits[16] = '\0';

    if (numero < 0) {
        printf("Conversao para complemento a 2 para o numero decimal %d:\n", numero);
        numero = -numero;

        printf("1. Representacao binaria do valor absoluto (%d):\n", numero);
        int i = 15;
        while (numero > 0 && i >= 0) {
            int resto = numero % 2;
            temp16bits[i] = resto + '0';
            printf("%d / 2 tem resto: %d\n", numero, resto);
            numero = numero / 2;
            i--;
        }
        printf("Resultado binario antes da inversao: %s\n", temp16bits);

        printf("2. Inverter todos os bits:\n");
        for (int j = 0; j < 16; j++) {
            temp16bits[j] = (temp16bits[j] == '0') ? '1' : '0';
        }
        printf("Resultado apos a inversao: %s\n", temp16bits);

        printf("3. Adicionar 1 ao resultado:\n");
        for (int j = 15; j >= 0; j--) {
            if (temp16bits[j] == '0') {
                temp16bits[j] = '1';
                break;
            } else {
                temp16bits[j] = '0';
            }
        }
        printf("Resultado apos adicionar 1: %s\n", temp16bits);
    } else {
        printf("Conversao do numero decimal %d para complemento a 2 de 16 bits:\n", numero);

        printf("1. Representacao binaria:\n");
        int i = 15;
        while (numero > 0 && i >= 0) {
            int resto = numero % 2;
            temp16bits[i] = resto + '0';
            printf("%d / 2 tem resto: %d\n", numero, resto);
            numero = numero / 2;
            i--;
        }
        printf("Resultado binario: %s\n", temp16bits);

        while (i >= 0) {
            temp16bits[i] = '0';
            i--;
        }
    }

    printf("Representacao binaria final: ");
    for (int i = 0; i < 16; i++) {
        printf("%c", temp16bits[i]);
        if (i % 4 == 3 && i != 15) {
            printf(" ");
        }
    }
    printf("\n");
}

void decimalParaFloat(double numero) {
    printf("Conversao do numero decimal %f para float:\n", (float)numero);

    float num = (float)numero;
    unsigned int *p = (unsigned int *)&num;

    unsigned int bitPattern = *p;

    int sinal = (bitPattern >> 31) & 0x01;
    int expoente = (bitPattern >> 23) & 0xFF;
    int fracao = bitPattern & 0x7FFFFF;

    printf("Bits: %08X\n", bitPattern);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d\n", expoente);
    printf("Expoente com vies: %d\n", expoente - 127);
    printf("Fracao: %07X\n", fracao);

    float fracaoDecimal = 1.0f;
    for (int i = 22; i >= 0; i--) {
        if ((fracao >> i) & 0x01) {
            fracaoDecimal += powf(2.0f, -(23 - i));
        }
    }
    printf("Fração decimal: %.6f\n", fracaoDecimal - 1.0f);
}

void decimalParaDouble(double numero) {
    printf("Conversao do numero decimal %lf para double:\n", numero);

    unsigned long long *p = (unsigned long long *)&numero;

    unsigned long long bitPattern = *p;

    int sinal = (bitPattern >> 63) & 0x01;
    int expoente = (bitPattern >> 52) & 0x7FF;
    long long fracao = bitPattern & 0xFFFFFFFFFFFFF;

    printf("Bits: %016llX\n", bitPattern);
    printf("Sinal: %d\n", sinal);
    printf("Expoente: %d\n", expoente);
    printf("Expoente com vies: %d\n", expoente - 1023);
    printf("Fracao: %013llX\n", fracao);

    double fracaoDecimal = 1.0;
    for (int i = 51; i >= 0; i--) {
        if ((fracao >> i) & 0x01) {
            fracaoDecimal += pow(2.0, -(52 - i));
        }
    }
    printf("Fracao decimal: %.16f\n", fracaoDecimal - 1.0);
}

int main() {
    int opcao;
    int numero;
    double numeroReal;

    printf("=====================================\n");
    printf("Calculadora de Bases Numericas :D\n");
    printf("=====================================\n");
    printf("1. Decimal para Binario\n");
    printf("2. Decimal para Octal\n");
    printf("3. Decimal para Hexadecimal\n");
    printf("4. Decimal para BCD\n");
    printf("5. Decimal para Base com sinal de 16 bits (Complemento a 2)\n");
    printf("6. Decimal para Float (com conversao para binario)\n");
    printf("7. Decimal para Double (com conversao para binario)\n");
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
        case 5:
            base10paraBase16bits(numero);
            break;
        case 6:
            printf("Digite o numero real: ");
            if (scanf("%lf", &numeroReal) != 1) {
                printf("Entrada invalida. Por favor insira um numero real.\n");
                return 1;
            }
            decimalParaFloat(numeroReal);
            break;
        case 7:
            printf("Digite o numero real: ");
            if (scanf("%lf", &numeroReal) != 1) {
                printf("Entrada invalida. Por favor insira um numero real.\n");
                return 1;
            }
            decimalParaDouble(numeroReal);
            break;
        default:
            printf("Opcao invalida\n");
    }
    return 0;
}
