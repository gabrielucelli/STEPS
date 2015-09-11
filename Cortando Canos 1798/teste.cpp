#include <stdio.h>
#include <string.h>

#define max(x,y) (x>y?x:y)

int n, t;

int c[5000+5], v[5000+5];
int memo[5000+5][1000+5];

int dp(int comprimento, int i)
{

  if(i == n)
    return 0;

  if(memo[comprimento][i] != -1)
    return memo[comprimento][i];

  if(comprimento < c[i])
    return memo[comprimento][i] = dp(comprimento, i+1);

  return memo[comprimento][i] = max(dp(comprimento, i+1), dp(comprimento - c[i], i) + v[i]);
}

int main()
{
  scanf("%d %d", &n, &t);
  memset(memo, -1, sizeof(memo));
  for(int i=0; i<n; i++)
  {
    scanf("%d %d", &c[i], &v[i] );
  }

  printf("%d\n", dp(t, 0) );

  return 0;
}
