#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Declaração da função func_val, conforme 3.2.2
int func_val(int x, int b) {
    // Realiza o cálculo da função proposta, arredondando o resultado
    double resultado = (double)(x % b) / b;
    return round(resultado);
}

// Função que decifra a mensagem
void decifrar_mensagem(int b, char* mensagem_cifrada) {
    int len = strlen(mensagem_cifrada);  // Calcula o tamanho da string
    char mensagem_decifrada[256];  // Buffer para a mensagem decifrada
    int idx = 0;  // Índice para construir a mensagem decifrada
    
    // Percorre a string de 2 em 2 caracteres
    for (int i = 0; i < len; i += 2) {
        // Converte os dois caracteres hexadecimais em valor decimal
        char temp[3] = {mensagem_cifrada[i], mensagem_cifrada[i+1], '\0'};
        int valor_decimal = (int)strtol(temp, NULL, 16);  // Conversão de hexadecimal para decimal
        
        // Chama a função func_val para verificar se o caractere deve ser incluído
        if (func_val(valor_decimal, b) != 0) {
            // Converte o valor decimal para caractere ASCII e adiciona à mensagem decifrada
            mensagem_decifrada[idx++] = (char)valor_decimal;
        }
    }
    mensagem_decifrada[idx] = '\0';  // Adiciona o terminador de string
    
    // Imprime a mensagem decifrada
    printf("%s\n", mensagem_decifrada);
}

int main() {
    int numero_casos;
    
    // Lê o número de casos de teste
    scanf("%d", &numero_casos);
    
    for (int i = 0; i < numero_casos; i++) {
        int b;
        char mensagem_cifrada[256];
        
        // Lê o valor de 'b'
        scanf("%d", &b);
        
        // Lê a string contendo a mensagem cifrada
        scanf("%s", mensagem_cifrada);
        
        // Decifra e imprime a mensagem
        decifrar_mensagem(b, mensagem_cifrada);
    }

    return 0;
}