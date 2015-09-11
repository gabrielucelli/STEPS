#include <stdio.h>
#include <math.h>

int main()
{
  int l,c,r1,r2;

  scanf("%d %d %d %d", &l, &c, &r1, &r2);

  if(sqrt(l*l + c*c) >= 2*r1 + 2*r2 + (r1 + r2)*(1 - sqrt(2)/2)) // Essa equação foi desenvolvida a partir de um circulo maximo dentro do elevador e um quadrado dentro desse circulo tirando a diferença entre os dois.
  {
    printf("S\n");
  }
  else
  {
    printf("N\n");
  }

  return 0;
}
