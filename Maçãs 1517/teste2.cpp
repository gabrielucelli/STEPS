#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(x,y)(x<y? x: y)
#define max(x,y)(x>y?x:y)

//12:40
//dp n m tempo
int dp[22][22][2000+2];
int mat[1005][5];
int n, m, k, x0, y0;

void clear()
{
  memset(dp, -1, sizeof(dp));
  memset(mat, 0, sizeof(mat));
}

int passos(int x0, int y0, int x, int y)
{
	int dx = x0 - x;
	int dy = y0 - y;
	if(dx<0) dx*=-1;
	if(dy<0) dy*=-1;

	return dx < dy? dy : dx;
}

int recur(int x0, int y0, int i, int tempo)
{
  if(dp[x0][y0][tempo] != -1)
    return dp[x0][y0][tempo];

  if(i == k)
      return 0;

  if(passos(x0, y0, mat[i][0], mat[i][1]) + tempo > mat[i][2])
  {
    //deu ruim
    return dp[x0][y0][tempo] = recur(x0, y0, i+1, tempo);
  }
  else
    return dp[x0][y0][tempo] = max(recur(mat[i][0], mat[i][1], i+1, mat[i][2]) + 1, recur(x0, y0, i+1, tempo));


}

int main()
{

  while(scanf("%d %d %d", &n, &m, &k) && n != 0 && m !=0 && k !=0)
  {
    clear();

    for(int i=0; i<k; i++)
    {
      scanf("%d %d %d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }

    scanf("%d %d", &x0, &y0);

    printf("%d\n",recur(x0, y0, 0, 0));

  }

  return 0;
}
