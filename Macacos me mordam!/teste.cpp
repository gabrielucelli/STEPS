#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

int n;

struct ponto
{
  int x, h;
};

int memo[100000+5];
ponto p[100000+5];

int verifica(float m, int i, int j)
{
  return (m*(p[j].x - p[i].x) + p[i].h) >= p[j].h;
}

int pode(int i, int j)
{
  float m = (float)(p[j].h - p[i].h);
  m/=(float)(p[j].x - p[i].x);

  for(int k=i+1; k<j; k++)
  {
    if(!verifica(m, i, k))
      return 0;
  }

  return 1;
}

int dp(int i)
{

  if(i==n-1)
    return 0;

  if(memo[i] != -1)
      return memo[i];

  int ans = (1<<30);

  for(int j=i+1; j<n; j++)
  {
    if(pode(i, j))
    {
      ans = min(ans, dp(j) + 1);
    }
  }

  return memo[i] = ans;
}

bool cmp(ponto i, ponto j)
{
  return i.x < j.x;
}

int main()
{
    scanf("%d", &n);
    for(int i=0; i<n; i++)
      scanf("%d %d", &p[i].x, &p[i].h);

    sort(p, p+n, cmp);
    memset(memo, -1, sizeof(memo));

    printf("%d\n", dp(0));

    return 0;
}
