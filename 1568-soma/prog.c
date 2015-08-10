#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	unsigned long long int MAX = 9e014;

	unsigned long long int i, j, k, numero;

	unsigned long long int *vet_crivo = (unsigned long long int*)malloc(MAX*sizeof(unsigned long long int));
	unsigned long long int lim;

	lim = (unsigned long long int)sqrt(MAX);

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

	while(scanf("%d\n", &numero)!=EOF)
	{

	}

	return 0;
}