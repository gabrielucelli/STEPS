#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>

using namespace std;

long long lado1, lado2, lado3, lado4;
long long P, Q, R, S, U, V, W, X; 

struct pontos
{
	long long x, y;
	long long indice;
};

bool handler(pontos A, pontos B)
{
	return A.indice < B.indice;
}

void distancia_entre_lados(pontos *ponto)
{
	//Distancia entre pontos
	lado1 = (ponto[0].x - ponto[1].x)*(ponto[0].x - ponto[1].x) + (ponto[0].y - ponto[1].y)*(ponto[0].y - ponto[1].y);
	lado2 = (ponto[1].x - ponto[2].x)*(ponto[1].x - ponto[2].x) + (ponto[1].y - ponto[2].y)*(ponto[1].y - ponto[2].y);
	lado3 = (ponto[2].x - ponto[3].x)*(ponto[2].x - ponto[3].x) + (ponto[2].y - ponto[3].y)*(ponto[2].y - ponto[3].y);
	lado4 = (ponto[3].x - ponto[0].x)*(ponto[3].x - ponto[0].x) + (ponto[3].y - ponto[0].y)*(ponto[3].y - ponto[0].y);

}

void angulo_entre_lados(pontos *ponto)
{
	//Checa angulo interno...
	P = (ponto[0].y - ponto[1].y) * (ponto[1].y - ponto[2].y) + (ponto[0].x - ponto[1].x) * (ponto[1].x - ponto[2].x);
	Q = (ponto[1].y - ponto[2].y) * (ponto[2].y - ponto[3].y) + (ponto[1].x - ponto[2].x) * (ponto[2].x - ponto[3].x);
	R = (ponto[2].y - ponto[3].y) * (ponto[3].y - ponto[0].y) + (ponto[2].x - ponto[3].x) * (ponto[3].x - ponto[0].x);
	S = (ponto[3].y - ponto[0].y) * (ponto[0].y - ponto[1].y) + (ponto[3].x - ponto[0].x) * (ponto[0].x - ponto[1].x);

	//Checa o paralelismo
	U = (ponto[0].y - ponto[1].y) * (ponto[2].x - ponto[3].x);
	V = (ponto[0].x - ponto[1].x) * (ponto[2].y - ponto[3].y);
	W = (ponto[1].y - ponto[2].y) * (ponto[0].x - ponto[3].x);
	X = (ponto[1].x - ponto[2].x) * (ponto[0].y - ponto[3].y);
}

int Retangulo(pontos *ponto)
{
	do
	{
			
		distancia_entre_lados(ponto);

		if(lado1 != lado3 || lado2 != lado4)continue;

		angulo_entre_lados(ponto);
	
		if(P == 0 && Q == 0 && R == 0 && S == 0)return 1;
	}while(next_permutation(ponto, ponto + 4, handler));

	return 0;
}

int Quadrado(pontos *ponto)
{
	do
	{
		distancia_entre_lados(ponto);
		if(lado1 != lado2 || lado2 != lado3 || lado3 != lado4 || lado4 != lado1)continue;

		angulo_entre_lados(ponto);
		if(P == 0 && Q == 0 && R == 0 && S == 0)return 1;
	}while(next_permutation(ponto, ponto + 4, handler));

	return 0;
}

int Losango(pontos *ponto)
{
	do
	{
		distancia_entre_lados(ponto);
		if(lado1 != lado2 || lado2 != lado3 || lado3 != lado4 || lado4 != lado1)continue;

		angulo_entre_lados(ponto);
		if(P == R && Q == S)return 1;
	}while(next_permutation(ponto, ponto + 4, handler));

	return 0;
}

int Paralelogramo(pontos *ponto)
{
	do
	{
		distancia_entre_lados(ponto);
		if(lado1 != lado3 || lado2 != lado4)continue;

		angulo_entre_lados(ponto);
		if(P != 0 && Q != 0 && R != 0 && S != 0 && U == V && W == X)return 1;
	}while(next_permutation(ponto, ponto + 4, handler));

	return 0;
}

int Trapezio(pontos *ponto)
{
	do{
		angulo_entre_lados(ponto);
		if((U == V) || (W == X))return 1;
	}while(next_permutation(ponto, ponto + 4, handler));

	return 0;
}

int main(void)
{
	int casos;
	scanf("%d", &casos);
	for(int j=0;j<casos;j++)
	{
		pontos ponto[4];
		for(int i=0;i<4;i++)
		{
			scanf("%lld %lld", &ponto[i].x, &ponto[i].y);
			ponto[i].indice = i;
		}
		printf("Case %d: ", j+1);
		if(Quadrado(ponto))printf("Square\n");
		else if(Retangulo(ponto))printf("Rectangle\n");
		else if(Losango(ponto))printf("Rhombus\n");
		else if(Paralelogramo(ponto))printf("Parallelogram\n");
		else if(Trapezio(ponto))printf("Trapezium\n");
		else printf("Ordinary Quadrilateral\n");
		
	}
	
}
