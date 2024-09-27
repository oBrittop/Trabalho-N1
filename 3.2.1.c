#include <stdio.h>
#include <limits.h>

int main() {
    int soma = 0, num = 2147483647;
    printf("Escreva um programa que use essa biblioteca e imprima os limites minimos e maximos que podem ser assumidos por variaveis dos tipos:\n");
    
    printf("O tipo CHAR tem como maximo %d e minimo %d\n", CHAR_MAX, CHAR_MIN);
    printf("O tipo INT tem como maximo %d e minimo %d\n", INT_MAX, INT_MIN);
    printf("O tipo SHORT INT tem como maximo %d e minimo %d\n", SHRT_MAX, SHRT_MIN);
    printf("O tipo UNSIGNED INT tem como maximo %u\n", UINT_MAX);
    printf("O tipo LONG INT tem como maximo %ld e minimo %ld\n", LONG_MAX, LONG_MIN);
    printf("O tipo UNSIGNED LONG INT tem como maximo %lu\n", ULONG_MAX);
    printf("O tipo LONG LONG tem como maximo %lld e minimo %lld\n", LLONG_MAX, LLONG_MIN);
    printf("O tipo UNSIGNED LONG LONG INT tem como maximo %llu\n", ULLONG_MAX);
    printf("Exemplos de quando nao obedecemos essa regra:\n");
    printf("Como vimos o int tem o maximo de 2147483647, mas se somamos mais  oq acontece ?\n" );
    printf("Digite um valor para somarmos com o valor maximo do tipo int");
    scanf("%d", &soma);
    printf("O resultado eh : %d + %d = %d", num, soma, num + soma);
    return 0;
}
