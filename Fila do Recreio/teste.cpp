#include <stdio.h>
#include <algorithm>
#include <string.h>

bool cmp(int a, int b)
{
  return a > b;
}

int main()
{
  int n, m;
  int vetor[1005];
  int vetor_aux[1005];

  scanf("%d", &n);

  for(int i=0; i<n; i++)
  {
    scanf("%d", &m);

    for(int j=0; j<m; j++)
    {
      scanf("%d", &vetor[j]);
    }

    memmove(vetor_aux, vetor, sizeof(vetor));

    std::sort(vetor, vetor+m, cmp);
    int cont = 0;

    for(int j=0; j<m; j++)
    {
      if(vetor[j]==vetor_aux[j])
        cont++;
      //printf("%d ", vetor[j] );
      //printf("%d ", vetor_aux[j] );
    }
    //printf("\n");

    printf("%d\n", cont);
  }

  return 0;
}
