#include <stdio.h>
#include <string.h>

#define max(x,y) (x>y?x:y)

int t[50 + 5], q[50 + 5];
int c, f;

int memo[1000 + 5][50 + 5];

int dp(int tamanho, int i)
{
  //printf("%d %d\n", tamanho, i );

  if(i == f)
    return 0;

  if(memo[tamanho][i] != -1)
    return memo[tamanho][i];

  if(tamanho < t[i])
    return memo[tamanho][i] = dp(tamanho, i+1);

  return memo[tamanho][i] = max(dp(tamanho, i+1), dp(tamanho - t[i], i+1) + q[i]);
}

int main()
{
  int k=0;
  while(scanf("%d %d", &c, &f) && c != 0 && f != 0)
  {
    memset(memo, -1, sizeof(memo));
    for(int i=0; i<f; i++)
    {
      scanf("%d %d", &t[i], &q[i]);
    }

    printf("Teste %d\n", ++k );
    printf("%d\n\n", dp(c, 0) );

  }
  return 0;
}
