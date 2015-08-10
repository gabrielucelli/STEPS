#include <stdio.h>

void swap(int *a, int* b)
{
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

int main()
{
	int i, n ,m, j, k, aux;
	scanf("%d %d",&n, &m);
	int vetor[n], vet_trocas[m];
	for(i=0; i<m; i++)
	{
		scanf("%d", &vet_trocas[i]);
	}

	for(i=0; i<n; i++)
	{
		vetor[i] = i + 1;
	}

	k = n - 1;

	for(i=m-1; i>=0; i--)
	{
		aux = k - vet_trocas[i];
		printf("aux = %d\n", aux);
		for(j=aux; j<k; j++)
		{	
			printf("j = %d\n", j );
			swap(&vetor[j], &vetor[j+1]);
		}
		k--;
	}

	for(i=0; i<n; i++)
	{
		printf("%d ", vetor[i] );
	}

	printf("\n");
	return 0;
}