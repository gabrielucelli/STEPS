#include <stdio.h>
#include <string.h>
#include <string>
#include <cctype>
#include <iostream>
#include <set>

using namespace std;
set<string> dic;

int main()
{
  char temp[205];
  string aux;

  while(scanf("%[A-Za-z]", &temp) != EOF)
  {
    getchar();
    aux = temp;
    for(int i=0; i < aux.size(); i++)
      aux[i] = tolower(aux[i]);
    dic.insert(aux);
  }

  set<string>::iterator it;

  for(it = dic.begin(); it != dic.end(); it++)
  {
    cout << (*it) << endl;
  }

  return 0;
}
