#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct pessoa
{
  char nome[11];
  int power;
};

pessoa pessoas[1000000+100];

int n;

long long int calculaA(int fim)
{
  long long int soma = 0;

  for(int i=fim-1; i>=0; i--)
  {
    soma+= (-1)*(i - fim)*pessoas[i].power;
  }

  return soma;
}

long long int calculaB(int inicio, int fim)
{
  long long int soma = 0;

  for(int i=inicio; i<fim; i++)
  {
    soma+=(i-inicio+1)*pessoas[i].power;
  }

  return soma;
}

int PesquisaBinaria(int inf, int sup)
{
    int meio;

    while (inf <= sup)
    {

      long long int aux1 = calculaA((inf+sup)/2);
      long long int aux2 = calculaB((inf+sup)/2, n);

      //printf("%lld %lld\n", aux1, aux2 );

      meio = (inf + sup)/2;

      if (aux1 == aux2)
      {
        return meio;
      }
      else if (aux1 > aux2)
      {
        sup = meio-1;
      }
      else
      {
        inf = meio+1;
      }
    }
    return -1;   // não encontrado
}

int main()
{

  while(scanf("%d", &n) && n!=0)
  {
    for(int i=0; i<n; i++)
    {
      scanf("%s", &pessoas[i].nome);
    }

    for(int i=0; i<n; i++)
    {
      pessoas[i].power = 0;

      for(int j=0; j<strlen(pessoas[i].nome);j++)
      {
        pessoas[i].power += pessoas[i].nome[j];
      }
    }

    for(int i=0; i<n; i++)
    {
      //printf("%s\n", pessoas[i].nome);
      //printf("%d\n", pessoas[i].power);
    }

    int aux = PesquisaBinaria(0,n);
    if(aux == -1)
    {
      printf("Impossibilidade de empate.\n");
    }
    else
      printf("%s\n", pessoas[aux-1].nome );
    //printf("%d\n", PesquisaBinaria(0,n) );
    //bin_search(0,n);
    //printf(">> %lld\n", calculaA(5));
    //printf(">> %lld\n\n", calculaB(5,n));
  }
  return 0;
}
