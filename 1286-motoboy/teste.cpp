#include <stdio.h>
#define max(x,y)(x>y?x:y)

int vetor_tempo[2000+5];
int vetor_pizza[2000+5];
int quant_pedidos, quant_sup, a;

int dp[2000+5][3000+5];

int main()
{

	while(1)
	{
		scanf("%d", &quant_pedidos);

		if(quant_pedidos==0)
		{
			return 0;
		}

		scanf("%d", &quant_sup);

		for(int i=1; i<quant_pedidos+1; i++)
		{
			scanf("%d %d\n", &vetor_tempo[i], &vetor_pizza[i]);
		}

		for(int i=0; i<quant_pedidos+1; i++)
			dp[0][i] = 0;

		for(int i=0; i<quant_sup+1; i++)
			dp[i][0] = 0;

		for(int i=1; i<quant_pedidos+1; i++)
		{
			for(int j=1; j<quant_sup+1; j++)
			{
				if(vetor_pizza[i] > j)
					dp[i][j] = dp[i-1][j];
				else
				{
					dp[i][j] = max(dp[i-1][j], dp[i-1][j-vetor_pizza[i]] + vetor_tempo[i]);
				}
			}
		}

		printf("%d min.\n", dp[quant_pedidos][quant_sup] );

	}

	return 0;
}
