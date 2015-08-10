#include <stdio.h>

char matriz[55][55];
int n,m;

int contamina(int x, int y)
{
  int flag = 0;

  if(y-1 >= 0)
  {
    if(matriz[x][y-1] == 'A')
    {
      matriz[x][y-1]= 'T';
      flag++;
    }
  }

  if(y+1 < m)
  {
    if(matriz[x][y+1] == 'A')
    {
      matriz[x][y+1]= 'T';
      flag++;
    }
  }

  if(x+1 < n)
  {
    if(matriz[x+1][y] == 'A')
    {
      matriz[x+1][y]= 'T';
      flag++;
    }
  }

  if(x-1 >= 0)
  {
    if(matriz[x-1][y] == 'A')
    {
      matriz[x-1][y]= 'T';
      flag++;
    }
  }
  /*if(x==0)
  {
    if(y == 0)
    {

    }
  }
  else if(x == n)
  {

  }
  else if(y == 0)
  {

  }
  else if(y == m)
  {

  }*/
  return flag;
}

int main()
{

  while(scanf("%d %d\n", &n, &m) && n!=0 && m!=0)
  {
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        scanf("%c", &matriz[i][j]);
      }
      getchar();
    }

    int mudanca = 1;

    while(mudanca != 0)
    {
      mudanca = 0;
      for(int i=0; i<n; i++)
      {
        for(int j=0; j<m; j++)
        {
          if(matriz[i][j] == 'T')
            mudanca += contamina(i,j);
        }
      }
    }

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        printf("%c", matriz[i][j]);
      }
      printf("\n");
    }

    printf("\n");
  }

  return 0;
}
