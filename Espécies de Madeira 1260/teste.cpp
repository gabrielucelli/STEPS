#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <string.h>

using namespace std;

map<string, int> trees;

int main()
{
  int c;
  string tree_temp;
  int tamanho;
  scanf("%d\n\n", &c);
  for(int i=0; i<c;i++)
  {
    trees.clear();
    tamanho=0;

    while(getline(cin, tree_temp) && tree_temp.size())
    {
      //cout << tree_temp << endl;
      tamanho++;
      if(trees.find(tree_temp)!=trees.end())
      {
        trees[tree_temp]+=1;
      }
      else
      {
        trees[tree_temp] = 1;
      }


    }

    map<string, int>::iterator it;

    for(it=trees.begin(); it!=trees.end(); it++)
    {
      cout << (*it).first;
      printf(" %.4f\n", (float)(*it).second*100 / tamanho );// << ' ' << (float)(*it).second*100 / tamanho << endl;
    }

    if(i!=c-1) cout << endl;

  }
  return 0;
}
