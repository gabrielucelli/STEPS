#include <stdio.h>
#include <string.h>

long long int dp[10000000];

void clear()
{
  memset(dp, -1, sizeof(dp));
}

long long int recu(long long int n, long long int k, long long int l)
{
  printf("%lld %lld %lld\n", n, k, l );

  if(dp[n] != -1)
    return dp[n];
  else
  {
    for(int i=0; i<k+l; i++)
    {

      if(n-10>=0)
      {
        return dp[n] += recu(n-10, k, l-1) + 1;
      }

      if(n-5>=0)
      {
        return dp[n] += recu(n-5, k-1, l) + 1;
      }

    }
  }

  printf("%lld\n\n", dp[n] );

  return dp[n];
}

int main()
{
  long long int n, k, l;
  while(scanf("%lld %lld %lld", &n, &k, &l) != EOF)
  {
    clear();
    recu(n,k,l);
    printf("%.6lld\n", dp[n-1]%1000000 );
  }
  return 0;
}
