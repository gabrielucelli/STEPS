#include <stdio.h>

int main()
{
  int n, dist, flag = 1;
  scanf("%d %d", &n, &dist);
  int vetor[n];
  for(int i=0; i<n; i++)
  {
    scanf("%d", &vetor[i]);
  }

  for(int i=0; i<n-1; i++)
  {
    if(vetor[i+1] - vetor[i] > dist)
    {
      flag = 0;
      break;
    }
  }

  if(42195 - vetor[n-1] > dist)
    flag = 0;

  if(flag)
    printf("S\n");
  else
    printf("N\n");

  return 0;
}
