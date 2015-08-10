#include <stdio.h>
#include <string.h>

int main()
{
  int n;
  while(scanf("%d", &n) && n!=0)
  {
    char nome_planeta[100];
    int menor_ano = 999999999;
    char aux_nome[100];
    int aux1, aux2;

    for(int i=0; i<n; i++)
    {
      scanf("%s %d %d", &aux_nome, &aux1, &aux2);

      if(aux1 - aux2 < menor_ano)
      {
        menor_ano = aux1 - aux2;
        strcpy(nome_planeta, aux_nome);
      }
    }

    printf("%s\n", nome_planeta );
  }
}
