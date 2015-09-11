#include <stdio.h>
#include <vector>


using namespace std;

#define MAX 1000000

int primos[MAX];
int n;
int cont = 0;

int prox(int i)
{
  for(int j = i; j<MAX; j++)
    if(primos[j] != 0)
      return j;
}

int main()
{

  for(int i = 0; i < MAX; i++)
    primos[i] = i;

  primos[0] = 0;
  primos[1] = 0;

  for(int i=2; i <= 1000; i++)
  {
      if(primos[i]==i)
      {
          for(int j=i+i; j<MAX; j = j + i)
          {
              primos[j]=0;
          }
      }
  }

  vector<int> h;
  vector<int>::iterator it;

  while(scanf("%d", &n) && n!= 0)
  {
    h.clear();

    for(int i = 0; i<n; i++)
      h.push_back(i+1);

    for(int i = prox(2), j = (i - 1)%h.size(); h.size() > 1; i = prox(i+1), j = (j + i - 1)%h.size())
    {
      it = h.begin() + j;
      //printf(">> %d\n", j);
      h.erase(it);
    }

    printf("%d\n", h[0]);

  }

  return 0;
}

/*1 2x 3 4 5x 6 / 4
1 3 4 x6 / 3
1x 3 4 / 2
3x 4 / 1*/
