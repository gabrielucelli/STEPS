#include <stdio.h>

void imprimir_vetor(int vetor[], int tamanho)
{
	int i;
	for(i=0; i< tamanho; i++)
	{
		printf("%d \n", vetor[i]);
	}
}

int euclides(int x, int y)
{
	int resto = x%y;

	if(resto == 0)
	{
		return y;
	}
	else
	{
		return euclides(y, resto);
	}

}

int main(int argc, char const *argv[])
{
	int i, j, k, a, cont, mmc;
	int n, b;

	while(1)
	{
		scanf("%d %d %d\n", &n, &a, &b);

		if( a == 0 && b ==0 && n == 0) return 0;

		cont = (int)n/a + (int)n/b;

		mmc = a*b / euclides(a, b);

		cont = cont - (int)n/mmc;

		printf("%d\n", cont );

	}
	
	

	return 0;
}