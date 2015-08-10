#include <string.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;
map<string, int> haypoint;

int main()
{
  int n, m;
  string aux;
  int temp;
  scanf("%d %d\n", &m, &n);

  for(int i=0; i<m; i++)
  {
    cin >> aux;
    scanf("%d\n", &temp);
    haypoint[aux] = temp;
  }

  for(int i=0; i<n; i++)
  {
    int ans = 0;
    while(cin >> aux && aux[0] != '.')
    {
      if(haypoint.find(aux) != haypoint.end())
      {
        ans+=haypoint[aux];
      }
    }
    printf("%d\n", ans );
  }

  return 0;
}
