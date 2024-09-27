#include <stdio.h>
#include <math.h> // Para a função round

#ifndef REMOVE_H
#define REMOVE_H

// Declaração da função
int func_val(int x, int b);

// Implementação da função
int func_val(int x, int b) {
    // Evita divisão por zero
    if (b == 0) {
        return 0; // Retorna 0 se b for 0
    }

    // Cálculo da divisão
    double result = (double)x / b;

    // Arredonda o resultado
    int rounded_result = (int)round(result);

    return rounded_result; // Retorna o valor arredondado
}

#endif /* REMOVE_H */

// Função principal
int main() {
    int x = 5; // Valor de exemplo
    int b = 2; // Divisor de exemplo

    int result = func_val(x, b);

    if (result == 0) {
        printf("Caractere deve ser ignorado.\n");
    } else {
        printf("Resultado: %d\n", result);
    }

    return 0;
}