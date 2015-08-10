#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y)(x<y? x: y)

//12:40

int dp[1005][1005];
int mat[1005][5];
int n, m, k, x0, y0;

void clear()
{
  memset(mat, 0, sizeof(mat));
}

void limparpd()
{
  memset(dp, -1, sizeof(dp));
}

/*int passos(int x0, int y0, int x, int y)
{
  int cont = 0;

  while(x0 != x || y0 != y)
  {
    if(x0 > x && y0 > y)//diagonal
    {
      x0--; y0--; cont++;
    }
    else if(x0 < x && y0 < y)//diagonal
    {
      x0++; y0++; cont++;
    }
    else if(x0 > x && y0 < y)//diagonal
    {
      x0--; y0++; cont++;
    }
    else if(x0 < x && y0 > y)//diagonal
    {
      x0++; y0--; cont++;
    }
    else if(x0 == x)
    {
      if(y0 > y)
      {
        y0--; cont++;
      }
      else
      {
        y0++; cont++;
      }
    }
    else if(y0 == y)
    {
      if(x0 > x)
      {
        x0--; cont++;
      }
      else
      {
        x0++; cont++;
      }
    }
  }

  return cont;

}*/

int passos(int x0, int y0, int x, int y)
{
	int dx = x0 - x;
	int dy = y0 - y;
	if(dx<0) dx*=-1;
	if(dy<0) dy*=-1;

	return dx < dy? dy : dx;
}

int recur(int x, int y, int tempo)
{

  int qmaca = 0;

  if(dp[x][y] != -1)
  {
    //printf(">> x = %d y = %d maca = %d\n", x, y, dp[x][y] );
    return dp[x][y];
  }

  for(int i=0; i<k; i++)
  {
    if(mat[i][3] == 0 && (passos(x, y, mat[i][0], mat[i][1]) + tempo <= mat[i][2]))
    {
      //printf("x0 = %d y0 = %d | x = %d y= %d | tempo = %d\n", x, y, mat[i][0], mat[i][1], mat[i][2]);
      mat[i][3] = 1; //visitado
      int aux = recur(mat[i][0], mat[i][1], mat[i][2]) + 1;
      qmaca = aux > qmaca ? aux : qmaca;
      //printf("%d\n", qmaca );
      mat[i][3] = 0;
    }
  }
//  printf("x = %d y = %d maca = %d\n", x, y, qmaca );
  //printf("\n");

  return dp[x][y] = qmaca;
}

int main()
{

  while(scanf("%d %d %d", &n, &m, &k) && n != 0 && m !=0 && k !=0)
  {
    clear();
    limparpd();

    for(int i=0; i<k; i++)
    {
      scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }

    scanf("%d %d", &x0, &y0);

    printf("%d\n",recur(x0, y0, 0));

  }

  return 0;
}
