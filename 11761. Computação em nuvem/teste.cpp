#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <limits.h>

using namespace std;

int d[500+5];
int p[500+5];
int k, l;

bool cmp(int a, int b)
{
  return a<b;
}

//ordenar crescentemente
//usar map
//K = servidores requisitads
//L = tipos de servidores
//iniciar com f(0,0)
//f(k, l) = min(f(k+1, l+1) + custo, f(k, l))
int memo_dp[500+5][500+5];
int memo_f[500+5][500+5];

int f(int i, int j)
{
  if(memo_f[i][j] != -1)
    return memo_f[i][j];
  return memo_f[i][j] = (j-i+1)*p[j];
}


int dp(int i, int j)
{
  if(i == 1)
    return f(0, j);


  if(memo_dp[i][j]!=-1)
      return memo_dp[i][j];

  int aux = (1 << 30) - 1;

  //if(j == 0)
    //return p[0];

  for(int q=0; q<j; q++)
  {
    //printf(" 1 - aux = min(%d, dp(%d-1, %d) + f(%d+1, %d));\n", aux, i,q,q, j );
    aux = min(aux, dp(i-1, q) + f(q+1, j));
    //printf(" 2 - aux = min(%d, dp(%d-1, %d) + f(%d+1, %d));\n", aux, i,q,q, j );
  }

  //printf("\n");

  return memo_dp[i][j] = aux;
}

/*int dp(int i, int tipo, int last)
{
  if(tipo > l && i <= k)
  {
    return 999999999;
  }

  if(i == k)
      return 0;

  if(memo[i][tipo][last] != -1)
        return memo[i][tipo][last];

  return memo[i][tipo][last] = std::min(dp(i+1, tipo, last) + p[last], dp(i+1, tipo+1, i) + p[i]);
}*/

int main()
{
  while(scanf("%d %d", &k, &l ) && k != 0 && l != 0)
  {
    for(int i =0; i<k; i++)
    {
      scanf("%d %d\n", &d[i], &p[i] );
    }

    memset(memo_f, -1, sizeof(memo_f));
    memset(memo_dp, -1, sizeof(memo_dp));

    std::sort(d, d+k, cmp);
    std::sort(p, p+k, cmp);

    /*for(int i=0; i<k; i++)
    {
      printf("%d %d\n", d[i], p[i] );
    }*/

    printf("%d\n", dp(l,k-1));
  }
  return 0;
}
