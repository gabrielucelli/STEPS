#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>

int n, b;


int c[100+5];
float p[100+5];
int escolhidos[100+5];

float memo[1000+5];

float robustez()
{
	float aux = 1;

	for(int i=0; i<n; i++)
	{
		aux*= (1 - pow(p[i], escolhidos[i]));
	}

	return aux;
}

float dp(int custo)
{

  //printf("custo: %d\n", custo );
	if(memo[custo] != 0)
	{
		//printf("-\n");
		return memo[custo];
	}

	for(int i=0; i<n; i++)
	{
		if(custo - c[i] > 0)
		{
			escolhidos[i]++;
			memo[custo] = std::max(memo[custo],std::max(robustez(), dp(custo - c[i])));
			escolhidos[i]--;
		}
	}

  memo[custo] = std::max(memo[custo], robustez());

	/*for(int i=0; i<n; i++)
	{
			printf("%d ", escolhidos[i]);
	}

	printf(" %f", memo[custo]);
		printf("\n");*/
	return memo[custo];
}

int main()
{
	int aux;

	while(scanf("%d %d", &n, &b) && n!=0 && b!=0)
	{
		aux = 0;
		for(int i=0; i<n; i++)
		{
			escolhidos[i] = 1;
			scanf("%d %f", &c[i], &p[i]);
			aux+=c[i];
		}

		memset(memo, 0, sizeof(memo));

    //for(int i=0; i<n; i++)
      //printf("%d ",  memo[i]);

    //printf("\n");

		if(b-aux > 0)
		{
			printf("%.3f\n", dp(b-aux));
		}
		else
		{
			printf("%.3f\n", 0.0);
		}

		/*for(int i=0; i<n; i++)
		{
			printf("%d ", escolhidos[i]);
		}
		printf("\n");*/


	}
	return 0;
}
