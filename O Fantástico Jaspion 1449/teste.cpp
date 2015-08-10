#include <stdio.h>
#include <string>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;


map<string, string> trad;

int main()
{
  int t,m,n;
  char c, aux2[85];
  char* aux3;
  string word_jap, word_port, aux;
  scanf("%d\n", &t);

  for(int j=0; j<t; j++)
  {
    trad.clear();
    scanf("%d %d\n", &m, &n);

    for(int i=0; i<m; i++)
    {
      getline(cin, word_jap);
      getline(cin, word_port);
      trad[word_jap] = word_port;
    }

    for(int i=0; i<n; i++)
    {
      if(scanf("%[^\n]", &aux2))
      {
        //printf(">> %s <<\n", aux2 );
        aux3 = strtok(aux2, " ");

        while(aux3 != NULL)
        {
          aux = aux3;

          if(trad.find(aux) != trad.end())
          {
            cout << trad[aux];
          }
          else
          {
            cout << aux;
          }

          aux3 = strtok(NULL, " ");

          if(aux3 != NULL)
            printf(" ");
        }

      }

      printf("\n");
      getchar();

    }

    cout << endl;


  }
  return 0;
}
