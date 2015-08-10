#include <stdio.h>

int main()
{
  int n, m, a, b;

  while(scanf("%d %d\n", &n, &m ) && n!= 0 && m!=0)
  {
    char matriz[n+1][m+1];

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        scanf("%c", &matriz[i][j]);
      }
      getchar();
    }

    /*for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        printf("%c", matriz[i][j]);
      }
      printf("\n");
    }*/


    scanf("%d %d", &a, &b);

    int ma = a/n;
    int mb = b/m;

    //printf("%d %d\n", ma, mb );

    for(int i=0; i<n; i++)
    {
      for(int k=0; k<ma; k++)
      {
        for(int j=0; j<m; j++)
        {
          for(int l=0; l<mb; l++)
          {
            printf("%c", matriz[i][j]);
          }
        }
        printf("\n");
      }
    }

    printf("\n");

  }
  return 0;
}
