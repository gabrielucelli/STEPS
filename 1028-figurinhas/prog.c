#include <stdio.h>
#include <math.h>

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
	
	int i, j, k;

	int num_instancia, f1, f2, resto;

	scanf("%d\n", &num_instancia);

	for (i = 0; i < num_instancia; i++)
	{
		scanf("%d %d\n", &f1, &f2);

		printf("%d\n", euclides(f1, f2));

	}

	return 0;
}