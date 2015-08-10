#include <stdio.h>
#include <stdlib.h>

int MDC(int a, int b)
{
  if (b == 0)
      return a;
  else
      return MDC(b, a % b);
}

int main()
{
  int x, y;
  while(scanf("%d %d", &x, &y) != EOF)
  {
    int particao = MDC(x, y);
    printf("%d\n", (x/particao + y/particao)*2 );
  }

  return 0;
}
