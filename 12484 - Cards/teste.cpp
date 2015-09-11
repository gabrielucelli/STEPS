#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n, a[10000+5];

//long long memo[2][10000+1];
long long memo[2][10000+1][10000+1];
char been[2][10000+1][10000+1];

int dp2(int i, int j);

int dp1(int i, int j)
{
  if(i == 0)
    return 0;

  if(been[0][i][j] != '0')
      return memo[0][i][j];

  been[0][i][j] = '1';

  return memo[0][i][j] = max(dp2(i-1, j+1) + a[j], dp2(i - 1, j) + a[j+i-1]);
}

int dp2(int i, int j)
{
  if(i == 0)
    return 0;

  if(been[0][i][j] != '0')
      return memo[1][i][j];

  been[0][i][j] = '1';

  return memo[1][i][j] = min(dp1(i-1, j + 1), dp1(i - 1, j));
}


int main()
{
  while(scanf("%d\n", &n ) != EOF)
  {
    for(int i=0; i<n; i++)
      scanf("%d", &a[i]);

    /*memset(memo, 0, sizeof(memo);
    for(int i = 0; i<n; i++)
    {
      for(int j = 0; j + i <n; j++)
      {
        if((i&1) == 1)//impar 2º jogador joga
  				  memo[0][j] = max(memo[1][j+1] + a[j], memo[1][j] + a[j+i]);
  				else
  					memo[1][j] = min(memo[0][j+1], memo[0][j]);
      }
    }
    printf("%lld\n", memo[0][0]);
    */

    memset(been, '0', sizeof(been));

    printf("%d\n", dp1(n, 0));

  }
  return 0;
}
