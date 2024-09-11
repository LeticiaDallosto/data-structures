// Faça uma rotina recursiva para calcular a somatória de todos os números de 1 a N (N será lido do teclado).

#include <stdio.h>
#include <locale.h>

int somatoria(int n) {
    if (n == 1) {
        return 1;
    } else {
        return n + somatoria(n - 1);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n;

    printf("Digite um número inteiro: ");
    scanf("%d", &n);
    int resultado = somatoria(n);
    printf("A somatória de 1 a %d é: %d\n", n, resultado);
    return 0;
}