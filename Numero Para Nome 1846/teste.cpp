#include <stdio.h>
#include <math.h>

char unidades[10][20] = {"","um", "dois", "tres", "quatro", "cinco", "seis", "sete", "oito", "nove"};
char dezenas[10][20] = {"dez","onze", "doze", "treze", "quartorze", "quinze", "dezesseis", "dezesete", "dezoito", "dezenove"};
char centenas[10][20] = {"cem", "ducentos", "trecentos", "quatrocentos", "quinhentos", "seicentos", "setecentos", "oitocento", "novecentos"};

int main()
{
  int n, tam;
  while(scanf("%d", &n) != EOF)
  {
    tam = log10(n) + 1;

    if(tam == 3)
    {
      printf("%s e ", centenas[n/100 - 1]);
      printf("%s e ", dezenas[(n%100)/10 - 1]);
      printf("%s\n", unidades[n%10]);
    }
  }
  return 0;
}
