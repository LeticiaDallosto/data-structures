// Escreva uma função que receba um caractere c e transforme c em uma string (cadeia de caracteres)
// Ou seja, devolva uma string de comprimento 1 tendo c como único elemento. 

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>

char *charToString(char c) {
   char str[2];
   str[0] = c;
   str[1] = '\0';
   return str;
}

int main() {
   char c;

   printf("Digite um caractere: ");
   scanf("%c", &c);

   char *stringResultado = charToString(c);
   printf("%s\n", stringResultado); 
}


