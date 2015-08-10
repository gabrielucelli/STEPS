#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

#define MAXN 501
#define MAXM MAXN*MAXN

float matriz[MAXN][2];

int orig[MAXM]; //origem da aresta i
int dest[MAXM]; //destino da aresta i
float custo[MAXM]; //custo da aresta i
//bool intree[MAXM]; //caso precise da arvore ao final
int ord[MAXM]; //auxiliar
int id[MAXN], sz[MAXN]; //uf auxiliar

void ufinit(int n)
{
  for (int i = 0; i < n; i++)
  id[i] = i, sz[i] = 1;
}

int uffind(int i)
{
  if (i == id[i]) return i;
  return id[i] = uffind(id[i]);
}
void ufunion(int v, int w)
{
  v = uffind(v); w = uffind(w);
  if (v == w)
    return;
  if (sz[v] > sz[w])
    swap(v,w);
  id[v] = w;
  if (sz[v] == sz[w])
    sz[w]++;
}

inline bool edgecmp(int i, int j)
{
  return (custo[i] < custo[j]);
}

inline float dist_pontos(float x0, float y0, float x, float y)
{
  return sqrt((x0-x)*(x0-x) + (y0-y)*(y0-y));
}

float kruskal(int n, int ne)
{
  float cost = 0;
  //memset(intree,0,sizeof(intree));
  for (int i = 0; i < ne; i++) ord[i] = i;
  sort(ord,&ord[ne],edgecmp);
  ufinit(n);
  int k = 0;
  for (int i = 0; i < ne && k < n; i++)
  {
    int v = ord[i];

    if (uffind(orig[v]) != uffind(dest[v]))
    {
      //intree[v] = true;
      ufunion(orig[v],dest[v]);
      cost += custo[v]; k++;
    }
  }
  return cost;
}
/*Exemplo de Uso*/
int main()
{
  int n, m,c;
  scanf("%d", &c);

  for(int i=0; i<c; i++)
  {

    scanf("%d", &n);

    for(int j=0; j<n; j++)
    {
      scanf("%f %f", &matriz[j][0], &matriz[j][1]);
    }

    int p = 0;

    for(int j=0; j<n; j++)
    {
      for(int k=0; k<n; k++)
      {
        if(k!=j)
        {
          orig[p] = j;
          dest[p] = k;
          custo[p++] = dist_pontos(matriz[j][0],matriz[j][1],matriz[k][0],matriz[k][1]);

        }
      }
    }

    printf("%.2f\n", kruskal(n,p)/100);

  }

  /*while (scanf("%d %d",&n,&m) == 2 && n != 0)
  {
    for (int i = 0; i < m; i++)
    {
      scanf("%d %d %d",&orig[m],&dest[m],&custo[m]);
    }
    printf("%d\n",kruskal(n,m));
  }*/

  return 0;
}
