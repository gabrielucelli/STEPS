#include <stdio.h>
#include <string.h>

int t[100+5];
int memo[10500 + 5];
int n;
int soma;

/*int dp(int x, int i)
{
  //printf(">> %d\n", x );
  if( x < 0)
    return 0;

  if(i == n)
  {
    //printf("%d\n", x );
    return x == 0;
  }

  if(memo[x][i] != -1)
    return memo[x][i];

  return memo[x][i] = (dp(x-t[i], i+1) || dp(x, i+1));
}*/

int dp(int x)
{
  memo[0] = 1;
  int max = 0;
  for (int i = 0; i < n && !memo[x]; i++)
  {
    for (int j = max; j >= 0; j--)
    	if (memo[j])
    	  memo[j+t[i]] = 1;
    max += memo[i];
  }
  return memo[x];
}

int main()
{
  int x,y, aux, k =0, temp;


  while(scanf("%d %d %d", &x, &y, &n) && x != 0 && y!=0 && n != 0)
  {
    memset(memo, 0, sizeof(memo));
    soma = 0;
    for(int i=0; i<n; i++)
    {
      scanf("%d", &t[i]);
      soma += t[i];
    }

    temp = (x + y + soma);
    //printf("%d\n", temp );

    if(temp % 2 != 0)
    {
      printf("Teste %d\nN\n\n", ++k);
    }
    else
    {
      temp/=2;
      //printf("%d\n", temp - x );
      aux = dp(temp - x);
      //printf("%d\n", aux );

      if(aux)
        printf("Teste %d\nS\n\n", ++k );
      else
        printf("Teste %d\nN\n\n", ++k);
    }

  }


  return 0;
}
