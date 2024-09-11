// Crie um programa em Linguagem C que conte os dígitos de um determinado número usando recursão.

#include <stdio.h>
#include <locale.h>

int fatorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * fatorial(n - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    int result = fatorial(n);
    printf("O fatorial de %d é %d\n", n, result);
    return 0;
}