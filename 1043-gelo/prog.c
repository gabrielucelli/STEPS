#include <stdio.h>

void imprimir_vetor(int vetor[], int tamanho)
{
	int i;
	for(i=0; i< tamanho; i++)
	{
		printf("%d ", vetor[i]);
	}
}

int min(int a, int b)
{
	if (a<b)
	{
	return a;
	} else
	{
	 return b;
	}
}

int main(int argc, char const *argv[])
{
	
	int i, j, k;

	int num_instancia, quant_blocos, comp_desejado;

	scanf("%d\n", &num_instancia);

	for (i = 0; i < num_instancia; i++)
	{
		scanf("%d %d\n", &quant_blocos, &comp_desejado);

		int blocos[quant_blocos];

		for(j=0; j<quant_blocos; j++)
		{
			scanf("%d ", &blocos[j]);
		}

		int vetor[comp_desejado+1];

		vetor[0] = 0;

		for(j=1; j<comp_desejado+1; j++)
		{
			vetor[j] = 10000000;

			for(k=0; k<quant_blocos; k++)
			{
				if( j >= blocos[k])
				{
					vetor[j] = min(vetor[j], vetor[j - blocos[k]] + 1);
				}
			}
		}

		
		printf("%d\n", vetor[comp_desejado]);

	}

	return 0;
}