#include <stdio.h>
#include <string.h>

int main()
{
  int n, m;
  while(scanf("%d %d", &n, &m) && n!= 0 && m!= 0)
  {
    int matriz[n+1][m+1];

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        scanf("%d", &matriz[i][j]);
      }
    }

    //primeiro caso
    int cont;
    int flag1;

    for(int i=0; i<n; i++)
    {
      cont = 0;

      for(int j=0; j<m; j++)
      {
        if(matriz[i][j] == 1)
          cont++;
      }

      if(cont==m)
      {
        flag1 = 0;
        break;
      }

      flag1 = 1;
    }

    //segundo caso
    int q_acc[m];
    int flag2 = 0;
    cont = 0;
    memset(q_acc, 0, sizeof(q_acc));

    for(int i=0; i<n; i++)
    {
      for(int j=0; j<m; j++)
      {
        if(matriz[i][j] == 1)
          q_acc[j]++;
      }
    }

    for(int i = 0; i<m; i++)
    {
      if(q_acc[i] != 0)
        cont++;
    }

    if(cont==m)
      flag2 = 1;

    //terceiro caso
    int flag3 = 0;

    for(int i=0; i<m; i++)
    {
      cont = 0;

      for(int j=0; j<n; j++)
      {
        if(matriz[j][i] == 1)
          cont++;
      }

      if(cont == n)
      {
        flag3 = 0;
        break;
      }

      flag3 = 1;
    }

    //quarto caso
    int flag4 = 0;
    for(int i=0; i<n; i++)
    {
      cont = 0;
      for(int j=0; j<m; j++)
      {
        if(matriz[i][j] == 1)
          cont++;
      }

      if(cont == 0)
      {
        flag4 = 0;
        break;
      }

      flag4 = 1;
    }


    //imprimindo
    printf("%d %d %d %d\n", flag1, flag2, flag3, flag4 );
    printf("%d\n", flag1 + flag2 + flag3 + flag4 );


  }
  return 0;
}
