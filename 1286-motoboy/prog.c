#include <stdio.h>

void imprimir_vetor(int vetor[], int tamanho)
{
	int i;
	for(i=0; i< tamanho; i++)
	{
		printf("%d \n", vetor[i]);
	}
}


int main(int argc, char const *argv[])
{
	
	int quant_pedidos, quant_sup, i, j, a;

	while(1)
	{
		scanf("%d", &quant_pedidos);

		if(quant_pedidos==0)
		{
			return 0;
		}

		scanf("%d", &quant_sup);

		int vetor_tempo[quant_pedidos];
		int vetor_pizza[quant_pedidos];

		for(i=0; i<quant_pedidos; i++)
		{
			scanf("%d %d\n", &vetor_tempo[i], &vetor_pizza[i]);

		}

		int tabela[quant_pedidos][quant_sup];


		for(i=0; i<quant_sup; i++)
		{

			for(j=0; j<quant_pedidos; j++)
			{
				if(i-vetor_pizza[j] < 0 || j ==0 )
				{
					a = vetor_tempo[j];
				}
				else
				{
					a = vetor_tempo[j] + tabela[j-1][i-vetor_pizza[j]];
				}

				if(vetor_pizza[j] > i+1)
				{

					if(j==0)
					{
						tabela[j][i] = 0;
					} 
					else
					{
						tabela[j][i] = tabela[j-1][i];
					}
				}
				else if (a > tabela[j-1][i] || j == 0)
				{
						tabela[j][i] = a;
				}
				else
				{
					tabela[j][i] = tabela[j-1][i];
				} 
			}
		}

		/*printf("%d %d \n", quant_pedidos, quant_sup);

		for(i=0; i< quant_pedidos; i++)
		{
			for (j=0; j<quant_sup; j++)
			{
			printf("%d ", tabela[i][j]);
			}

		printf("\n");
		}*/

		printf("%d min.\n", tabela[quant_pedidos-1][quant_sup-1] );

	}

	return 0;
}