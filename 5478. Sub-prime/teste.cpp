#include <stdio.h>
#include <stdlib.h>

int main()
{
  int b, n;

  while(scanf("%d %d", &b, &n) && b != 0 && n!=0)
  {
    int vetor_bancos[b];
    int vetor_aux[b];

    for(int i = 0; i<b; i++)
    {
      scanf("%d", &vetor_bancos[i]);
    }

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<3; j++)
      {
        scanf("%d", &vetor_aux[j]);
      }

      vetor_bancos[vetor_aux[0] - 1] -= vetor_aux[2];
      vetor_bancos[vetor_aux[1] - 1] += vetor_aux[2];
    }

    int flag = 0;

    for(int i=0; i<b; i++)
    {
      if(vetor_bancos[i] < 0)
      {
        flag = 1;
      }
    }

    if(!flag)
      printf("S\n");
    else
      printf("N\n");

  }
  return 0;
}
