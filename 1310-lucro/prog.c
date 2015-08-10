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
	int num_dia, custo_dia, maiorLucro=0;
	int i, j;

	while(scanf("%d\n", &num_dia)!=EOF)
	{
		scanf("%d\n", &custo_dia);

		int vetor_receita[num_dia];

		for(i=0; i< num_dia; i++)
		{
			scanf("%d\n", &vetor_receita[i]);
			vetor_receita[i] = vetor_receita[i] - custo_dia;
		}

		maiorLucro = 0;

		int tabela[num_dia][num_dia];

		tabela[0][0] = 0;

		for (i=0; i < num_dia; ++i)
		{
			for(j=i; j < num_dia; j++)
			{	
				if(j==i)
				{
					tabela[j][i] = vetor_receita[i];
				}
				else
				{				
					tabela[j][i] = tabela[j-1][i] + vetor_receita[j];
				}

				if(tabela[j][i] > maiorLucro)
				{
					maiorLucro = tabela[j][i];
				}
			}
		}

		printf("%d\n", maiorLucro );
		/*printf("%d %d \n", quant_pedidos, quant_sup);
	
		for(i=0; i< num_dia; i++)
		{
			for (j=0; j<num_dia; j++)
			{
			printf("%d ", tabela[i][j]);
			}

		printf("\n");
		}
		*/

		
	}

	return 0;
}