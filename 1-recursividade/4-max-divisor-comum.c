// Crie um programa que calcula o máximo divisor comum entre dois números usando a recursão.

#include <stdio.h>
#include <locale.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int n1, n2;

    printf("Digite dois números inteiros: ");
    scanf("%d %d", &n1, &n2);
    int result = mdc(n1, n2);
    printf("O máximo divisor comum é: %d\n", result);
    return 0;
}
