#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float validador(int x, int b) {
    float a0 = 186.752;
    float a1 = -148.235;
    float a2 = 34.5049;
    float a3 = -3.5091;
    float a4 = 0.183166;
    float a5 = -0.00513554;
    float a6 = 0.0000735464;
    float a7 = -4.22038e-7; // Corrigido para notacao cientifica

    // Calcula f(x, b)
    return a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) + 
           a4 * pow(x, 4) + a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7);
}

int main() {
    int x[50] = {0}, b[50] = {0};
    char hex_message[101]; // 100 para hexa e + 1 para null terminator

    printf("Digite os caracteres (valores de 1 a 50):\n");
    for (int i = 0; i < 50; i++) {
        printf("Caractere %d: ", i + 1);
        scanf("%d", &x[i]);
    }

    printf("Digite os valores de 'b' (valores de -100 a 100):\n");
    for (int i = 0; i < 50; i++) {
        printf("Referente a posicao [%d]: ", x[i]);
        scanf("%d", &b[i]);
    }

    printf("Digite a mensagem hexadecimal (max 100 caracteres):\n");
    scanf("%s", hex_message);

    // Decodificar a mensagem hexadecimal
    printf("Mensagem decodificada:\n");
    for (int i = 0; i < strlen(hex_message); i += 2) {
        char hex_pair[3] = {hex_message[i], hex_message[i + 1], '\0'};
        int byte_value = (int)strtol(hex_pair, NULL, 16); //strol  converter para decimal

        // Ignorar o byte se for 0
        if (byte_value == 0) {
            break; // Encerra a mensagem se encontrar 00
        }

        // Usar validador para verificar se deve ignorar ou nao
        int pos = i / 2 + 1; // Posicao comecando em 1
        if (validador(pos, b[pos - 1]) >= 0 && validador(pos, b[pos - 1]) < 256) {
            printf("%c", (char)byte_value); // Imprime o caractere se for valido
        }
    }
    printf("\n");

    return 0;
}
