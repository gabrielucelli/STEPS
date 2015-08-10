#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

//inicialmente temos parent[x] = x e rank[x] = 0

int a[10000+5], n;
int parent[10000+5], rank[10000+5];
set<int> myset;

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void uunion(int a, int b) {
    int x = find(a), y = find(b);
    if (x==y) return;

    if (rank[x] < rank[y]) {
        parent[x] = y;
    }
    else {
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
    }
}

void begin()
{
  for(int i=0; i<n+1; i++)
  {
    parent[i] = i;
    rank[i] = 0;
  }
  myset.clear();
}


int main()
{
  int cont, t;
  int aux;
  scanf("%d", &t);
  
  for(int i=0; i<t; i++)
  {
    scanf("%d", &n);
    begin();

    for(int j=0; j<n; j++)
    {
      scanf("%d", &a[j]);
    }


    for(int j=0; j<n; j++)
    {
      uunion(j, a[j] - 1);
    }

    for(int j = 0; j<n; j++)
    {
      aux = find(j);
      myset.insert(aux);
    }

    printf("%d\n", n - myset.size() );
  }
  return 0;
}
