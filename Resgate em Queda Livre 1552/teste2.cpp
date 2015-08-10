#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <queue>
#include <limits.h>

using namespace std;
#define MAXN 501 //numero maximo de vertices
#define INF INT_MAX //nao ha perigo de overflow
float matriz[MAXN][2];

int adj[MAXN][MAXN]; //lista de adj
float custo[MAXN][MAXN]; //tamanho das arestas de adj
int nadj[MAXN]; //grau de cada vertice
int pai[MAXN]; //para reconstruir o caminho
float dist[MAXN]; //distancia de cada vertice a arvore
bool used[MAXN];
/*
n: numero de vertices, s: origem (opcional)
retorna peso total da arvore
*/
float prim(int n, int s = 0)
{
  priority_queue<pair<float, int> > q;
  int a,v;
  float cost, nv = 0;
  float ret = 0;
  memset(pai,-1,sizeof(pai));
  memset(used,0,sizeof(used));
  for (int i = 0; i < n; i++) dist[i] = INF;
  dist[s] = 0;
  pai[s] = s;
  q.push(make_pair(0,s));
  while(!q.empty() && nv < n)
  {
    a = q.top().second;
    q.pop();
    if (used[a]) continue;
    ret += dist[a];
    used[a] = true;
    nv++;
    for (int i = 0; i < nadj[a]; i++)
    {
      v = adj[a][i];
      if (used[v]) continue;
      cost = custo[a][i];
      if (cost >= dist[v]) continue;
      dist[v] = cost;
      q.push(make_pair(-1*cost,v));
      pai[v] = a;
    }
  }
  return ret;
}

inline float dist_pontos(float x0, float y0, float x, float y)
{
  return sqrt((x0-x)*(x0-x) + (y0-y)*(y0-y));
}
/**** Exemplo simples de uso ****/
int main()
{

  int n, m,c;
  int from, to;
  float cost;
  scanf("%d", &c);

  for(int i=0; i<c; i++)
  {


    scanf("%d", &n);
    memset(nadj,0,sizeof(nadj));

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
          from = j;
          to = k;
          cost = dist_pontos(matriz[j][0],matriz[j][1],matriz[k][0],matriz[k][1]);

          custo[from][nadj[from]] = custo[to][nadj[to]] = cost;
          adj[from][nadj[from]++] = to;
          adj[to][nadj[to]++] = from;

        }
      }
    }

    printf("%.2f\n", prim(n)/100);

  }
/*

    memset(nadj,0,sizeof(nadj));
    for (int i = 0; i < m; i++)
    {
      scanf("%d %d %d",&from,&to,&cost);
      custo[from][nadj[from]] = custo[to][nadj[to]] = cost;
      adj[from][nadj[from]++] = to;
      adj[to][nadj[to]++] = from;
    }
    printf("%d\n",prim(n));
  }
  */
  return 0;
}
