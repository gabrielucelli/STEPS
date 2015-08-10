#include <algorithm>
#include <stdio.h>
#include <stdlib.h>

int verificar(int* vet, int tamanho, int cows, int x)
{
	int i, cont=1;
	int pos=0;

	for(i=1; i<tamanho; i++)
	{
		if((vet[i]-vet[pos]) >= x)
		{
			if(++cont == cows)
			{
				return 1;
			}

			pos = i;
		}
	}

	return 0;
}

int main()
{
	int casos, n, c, j, i, k;
	scanf("%d\n", &casos);

	for(i=0; i<casos; i++)
	{
		scanf("%d %d\n", &n, &c);
		int vet[n];

		for(j=0; j<n; j++)
		{
			scanf("%d\n", &vet[j]);
		}

		std::sort(vet, vet+n);

		int fim = vet[n-1] - vet[0];
		int inicio = 0;
		int meio;
	
		while(fim > inicio + 1)
		{
			meio = (fim + inicio) >> 1;
			if(verificar(vet, n, c, meio))
			{
				inicio = meio;
			} else fim = meio;

			//printf(">> %d\n", meio);
		

		}

		printf("%d\n", inicio);
		
	}

return 0;
}