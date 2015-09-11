#include <stdio.h>
#include <vector>

using namespace std;

int main()
{

  int c, n, k, t=0;
  vector<int> h;
  scanf("%d", &c);

  for(int i=0; i<c; i++)
  {
    scanf("%d %d", &n, &k);
    h.clear();

    for(int j=0; j<n; j++)
      h.push_back(j+1);

    vector<int>::iterator it;

    for(int j = (k-1)%h.size(); h.size() > 1; j = (j+k-1)%h.size())
    {
      it = h.begin() + j;
      h.erase(it);
    }

    printf("Case %d: %d\n", ++t, h[0] );


  }
  return 0;

}
