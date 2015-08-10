#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int MAX = 100001;

	int i, j, k;
	int num_casos, n;

	int *vet_crivo; vet_crivo = (int*)malloc(MAX*sizeof(int));
	int lim;

	lim = (int)sqrt(MAX);

	for(i=0; i< MAX; i++)
	{
		vet_crivo[i] = i;
	}

	vet_crivo[0]=0;
	vet_crivo[1]=0;

	for(i=2; i <= lim; i++)
	{
		if(vet_crivo[i]==i)
		{
			for(j=i+i; j<MAX; j = j + i)
			{
				vet_crivo[j]=0;
			}
		}
	}


	scanf("%d\n", &num_casos);

	for(i=0; i<num_casos; i++)
	{
		scanf("%d\n", &n);

		int vetor[n];
		int begin;
		int save;

		for(j=0; j<n; j++)
		{
			scanf("%d ", &vetor[j]);
		}

		begin = vetor[0];

		for(j=0; j< n; j++)
		{
			if ( vetor[j]==vet_crivo[begin])
			{
				save = begin;
			}

			begin++;
		}

		for(j=save+1; j<MAX; j++)
		{
			if(vet_crivo[j]!=0)
			{
				save =  vet_crivo[j] - 1;

				if(save == vetor[n-1])
				{
					save = 0;
				}

				break;
			}
		}

		printf("%d\n", save );
	}

	return 0;
}