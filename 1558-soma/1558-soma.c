#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int i, j;
	int atual, temp, cont;
	int **matriz;
	matriz = (int**)malloc(1001*sizeof(int *));
	for (i=0; i<1001; i++)
	{
		matriz[i] = (int*)malloc(sizeof(int)*1001);
	}
	
	int maior_num=0;
	int num;
	while(scanf("%d", &atual)!=EOF)
	{
		num = (int)sqrt(atual);
		if(num>maior_num)
		{
			for(i=0; i<num; i++)
			{
			if(i==num-1) maior_num=0;
				for(j=maior_num; j<num; j++)
				{
					matriz[i][j]=(i+1)*(i+1) + (j+1)*(j+1);
				}
			}
		maior_num=num;	
		}
		
		for(i=0; i<maior_num; i++)
		{
			for(j=i; j<maior_num; j++)
			{
				if (matriz[i][j]==atual)
				{
				printf("YES\n");
				cont=1;
				break;
				}
			}
		if(cont==1) break;		
		}
		
		if(cont == 0)
		{
			printf("NO\n"); 
		}
		
		cont = 0;
	
	}
	
	for (i=0; i<1001; i++)
	{
		free (matriz[i]);
	}
	
	free(matriz);
	
	return 0;
}