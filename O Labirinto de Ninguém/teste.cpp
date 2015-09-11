#include <stdio.h>
#include <algorithm>
#include <ctype.h>
#include <string.h>

using namespace std;

char mapa[100+5][100+5];
int been[100+5][100+5];
int key[7];
int n, m; //m colunas e n linhas

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int pode(int x, int y)
{
  if(x < 0 || y < 0 || x > n + 1 || y > m + 1 || been[y][x] == 1)
    return 0;
  else
    return 1;
}

int c(int x, int y)
{
  printf("%d %d %c\n", x, y, mapa[y][x] );
  int aux_x, aux_y;

  int aux = 9999;

  if(mapa[y][x] == '*')
  {
    //printf("OIII\n");
    return 0;
  }

  for(int i = 0; i < 4; i++)
  {
    aux_x = dx[i] + x;
    aux_y = dy[i] + y;

    if(pode(aux_x, aux_y))
    {
      if(mapa[aux_y][aux_x] == '.')
      {
        //printf("%d %d\n", aux_x, aux_y );
        been[y][x] = 1;
        aux = min(aux, c(aux_x, aux_y) + 1);
        been[y][x] = 0;
      }
      else if(islower(mapa[aux_y][aux_x]) && mapa[aux_y][aux_x] != '#')
      {
        key[mapa[aux_y][aux_x] - 'a'] = 1;
        been[y][x] = 1;
        aux = min(aux, c(aux_x, aux_y) + 1);
        been[y][x] = 0;
        key[mapa[aux_y][aux_x] - 'a'] = 0;
      }
      else if(isupper(mapa[aux_y][aux_x]) && mapa[aux_y][aux_x] != '#')
      {
        if(key[mapa[aux_y][aux_x] - 'A'])
        {
          been[y][x] = 1;
          aux = min(aux, c(aux_x, aux_y) + 1);
          been[y][x] = 0;
        }
      }
      else if(mapa[aux_y][aux_x] == '*')
      {
          been[y][x] = 1;
          aux = min(aux, c(aux_x, aux_y) + 1);
          been[y][x] = 0;
      }
    }
  }

  return aux;
}



int main()
{
  char aux;
  int i=0, j=0, x0, y0;

  while(scanf("%c", &aux)!=EOF)
  {
    if(aux != '\n')
    {
      if(aux == '@')
      {
        x0 = j; y0=i;
      }

      mapa[i][j++] = aux;
    }
    else
    {
      m = max(m, j);
      i++;
      j=0;
    }
  }

  n = i;

  memset(been, 0, sizeof(been));
  memset(key, 0, sizeof(key));

  printf("%d\n", c(x0, y0));
  /*for(int l=0; l<i+1; l++)
  {
    for(int k=0; k<m+1; k++)
    {
      printf("%c", mapa[l][k]);
    }
    printf("\n");
  }*/

  return 0;
}
