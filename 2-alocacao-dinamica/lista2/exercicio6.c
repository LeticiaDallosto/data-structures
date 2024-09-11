// O que há de errado com o seguinte trecho de código?

/*
char *a, *b;
a = "abacate";
b = "uva";
if (a < b)
   printf ("%s vem antes de %s no dicionário", a, b);
else
   printf ("%s vem depois de %s no dicionário", a, b);
*/

/*
Apesar do resultado mostrar corretamente que abacate vem antes da uva no dicionario,
a comparação está sendo feita por endereco de memoria
a comparação esta sendo feita em relação a qual alocação de memoria vem antes da outra e não a palavra no dicionario
*/




