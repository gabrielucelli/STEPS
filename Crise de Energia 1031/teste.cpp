#include "stdio.h"
#include "stdlib.h"
#include "vector"

using namespace std;

int main()
{
  int m;

  while(scanf("%d", &m) && m!=0)
  {
    vector<int> cidades;
    vector<int>::iterator it;

    for(int n = 1; ; n++)
    {
      cidades.clear();
      for(int i=0; i<m; i++)
      {
        cidades.push_back(i+1);
      }

      int p = - n + 1;

      while(cidades.size() > 1)
      {
        p += n - 1;
        if(p >= cidades.size())
          p %= cidades.size();

        it = cidades.begin();
        it += p;
        cidades.erase(it);
      }

      it = cidades.begin();

      //printf("n=%d it=%d\n", n, *it );

      if(*it == 13)
      {
        printf("%d\n", n);
        break;
      }
    }

  }

  return 0;
}
