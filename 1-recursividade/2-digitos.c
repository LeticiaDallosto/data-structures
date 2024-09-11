// Crie um programa em Linguagem C que conte os dígitos de um determinado número usando recursão.

#include <stdio.h>
#include <locale.h>

int contDigitos(int num) {
    if (num == 0) {
        return 0;
    } else {
        return 1 + contDigitos(num / 10);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    
    int digitCount = contDigitos(n);
    printf("O número de dígitos é: %d\n", digitCount);
    
    return 0;
}