#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>


int main()
{
  int n, m;
  while(scanf("%d %d", &n, &m) && n!=0 && m!=0)
  {
    int vetor_perm[m];

    for(int i =0; i<m; i++)
    {
      scanf("%d", &vetor_perm[i]);
    }

    int vetor[n];

    for(int i=0; i<n; i++)
      vetor[i] = i + 1;

    if(m==1)
    {
      std::swap(vetor[0], vetor[1]);
    }
    else
    {
      for(int i=0; i<m; i++)
      {
        int perm = vetor_perm[m-i-1];
        int indice_swap = n - i - 2;

        //printf("perm: %d\n", perm);
        //printf("indice_swap: %d\n", indice_swap);

        /*for(int i =0; i<n; i++)
        {
          printf("%d ", vetor[i]);
        }
        printf("\n" );
        */

        int aux = vetor[indice_swap];

        memmove(&vetor[indice_swap], &vetor[indice_swap+1], perm*sizeof(int));
        vetor[indice_swap+perm] = aux;
        //std::swap(vetor[indice_swap+j], vetor[indice_swap+j-1]);

        /*for(int i =0; i<n; i++)
        {
          printf("%d ", vetor[i]);
        }
        printf("\n" );
        printf("<<<<<>>>>>\n" );
        */
      }
    }

    for(int i =0; i<n; i++)
    {
      printf("%d ", vetor[i]);
    }
    printf("\n" );
  }
  return 0;
}
