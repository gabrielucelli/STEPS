#include <stdio.h>

int main()
{
  char s[1000];
  int soma;
  for(int i=0; i<3; i++)
  {
    soma = 0;
    while(scanf("%[^\n]\n", &s) && s[0] != 'c')
    {
      for(int j=1; j<=3; j++)
        if(s[j-1] == '*')
          soma += (1 << (3 - j));
        //printf("%s\n",s );
    }
      //printf("%s\n",s );
    printf("%d\n", soma );
  }

  return 0;
}
