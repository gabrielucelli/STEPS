#include <stdio.h>

int vetor[100 + 5];
int nPaineis, caminhoes, frete;

int verifica(int val)
{
  int soma = 0;
  int carros = 1;

  for(int i=0; i<nPaineis; i++)
  {
    if(soma + vetor[i] > val && soma <= val)
    {
      carros++;
      soma = 0;
    }

    soma+= vetor[i];
  }

  //printf("%d\n", carros );
  //printf("%d\n", soma);

  if(soma <= val && carros <= caminhoes)
    return 1;
  else
    return 0;
}

int busca_binaria(int inf, int sup)
{
  int aux = verifica((inf+sup)/2);
  //printf("%d %d\n", inf, sup );

  if(inf >= sup)
    return sup;
  if(!aux)
    return busca_binaria((inf+sup)/2+1, sup);
  else if(aux)
    return busca_binaria(inf, (sup+inf)/2);
}



int main()
{
  int c, soma;
  scanf("%d", &c);
  for(int i=0; i<c; i++)
  {
    scanf("%d %d %d\n", &nPaineis, &caminhoes, &frete );
    soma = 0;
    for(int j=0; j<nPaineis; j++)
    {
      scanf("%d", &vetor[j]);
      soma +=vetor[j];
    }

    int aux = busca_binaria(0, soma);
    printf("%d $%d\n", aux, aux*caminhoes*frete);

  }
  return 0;
}
