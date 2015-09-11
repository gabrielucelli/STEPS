#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int n, m;
int memo[10000 + 5];
int been[10000 + 5];

int dp(int num)
{
  printf(">> num = %d\n", num );

  if(num == m)
    return 0;

  int aux = 9999999;

  if(num > 3*m)
  {
  aux = min(aux, dp(n/2) + 1);
    aux = min(aux, dp(n/3) + 1);
  aux = min(aux, dp(n-7) + 1);
  }

  if(num > 0)
  {
    aux = min(aux, dp(n*2) + 1);
    aux = min(aux, dp(n*3) + 1);
    aux = min(aux, dp(n+7) + 1);
  }

  return aux;
}

int main()
{
  memset(been, -1, sizeof(been));
  scanf("%d %d\n", &n, &m );
  printf("%d\n", dp(n) );
  return 0;
}
