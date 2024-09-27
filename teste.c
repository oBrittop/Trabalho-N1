#include <stdio.h>
#include <stdlib.h>

float func_val(int x, float b) {
    // Coeficientes da função
    float a0 = 186.752;
    float a1 = -148.235;
    float a2 = 34.5049;
    float a3 = -3.5091;
    float a4 = 0.183166;
    float a5 = -0.00513554;
    float a6 = 0.0000735464;
    float a7 = -4.22038e-7;
    
    // Cálculo da função f(x, b)
    return a0 + (a1 + b) * x + a2 * x * x + a3 * x * x * x +
           a4 * x * x * x * x + a5 * x * x * x * x * x +
           a6 * x * x * x * x * x * x + a7 * x * x * x * x * x * x * x;
}

int main() {
    char hexInput[101]; // 50 caracteres hexadecimais (2 chars cada) + 1 para '\0'
    printf("Digite a mensagem codificada em hexadecimal (máx. 50 caracteres): ");
    scanf("%100s", hexInput); // Lê até 100 caracteres (50 bytes)

    // Variáveis
    char decodedMessage[51]; // Para armazenar a mensagem decodificada (50 caracteres + '\0')
    int msgIndex = 0; // Índice da mensagem
    int pos = 1; // Posição do caractere, começando de 1
    float b; // Variável b que será dada pelo agente da inteligência

    // Loop para processar cada caractere
    for (int i = 0; i < 100; i += 2) {
        // Verifica se encontramos '00', que indica o fim da mensagem
        if (hexInput[i] == '0' && hexInput[i + 1] == '0') {
            break;
        }
        
        // Converte dois caracteres hexadecimais em um único caractere
        char hexPair[3] = {hexInput[i], hexInput[i + 1], '\0'};
        int charValue = (int)strtol(hexPair, NULL, 16);
        
        // Receber a variável b (pode ser hardcoded para testes ou recebido via entrada)
        printf("Digite o valor de b para a posição %d: ", pos);
        scanf("%f", &b);

        // Calcula o valor da função f(x, b)
        float result = func_val(pos, b);

        // Se o resultado for 0, ignora o caractere
        if (result == 0) {
            continue;
        }
        
        // Verifica se o caractere é um valor ASCII válido
        if (charValue >= 32 && charValue <= 126) { // Intervalo de caracteres imprimíveis na tabela ASCII
            decodedMessage[msgIndex++] = (char)charValue;
        }
        
        pos++; // Incrementa a posição
    }

    // Adiciona o terminador de string
    decodedMessage[msgIndex] = '\0';

    // Imprime a mensagem decodificada
    printf("Mensagem Decodificada: %s\n", decodedMessage);

    return 0;
}