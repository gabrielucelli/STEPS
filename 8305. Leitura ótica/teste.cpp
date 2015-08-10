#include <stdio.h>

int main()
{

  int n, aux, flag, indice;

  while(scanf("%d", &n) && n!=0)
  {
    for(int i=0; i<n; i++)
    {
      flag = 0;

      for(int j=0; j<5; j++)
      {
        scanf("%d", &aux);

        if(aux <= 127)
        {
          indice = j;
          flag++;
        }
      }

      if(flag == 1)
      {
        if(indice == 0)
        {
          printf("A\n");
        }
        else if(indice == 1)
        {
          printf("B\n");
        }
        else if(indice == 2)
        {
          printf("C\n");
        }
        else if(indice == 3)
        {
          printf("D\n");
        }
        else if(indice == 4)
        {
          printf("E\n");
        }
      }
      else
        printf("*\n");
    }
  }
  return 0;
}
