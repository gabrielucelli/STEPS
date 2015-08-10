#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
  int cases;
  scanf("%d", &cases);
  char palavra[17];
  for(int i=0; i<cases; i++)
  {
    scanf("%s", palavra);
    int ans = 1;
    for(int j=0; j<strlen(palavra); j++)
    {
      char a = palavra[j];

      if('a' == tolower(a))
      {
        ans*=3;
      }
      else if('e' == tolower(a))
      {
        ans*=3;
      }
      else if('i' == tolower(a))
      {
        ans*=3;
      }
      else if('o' == tolower(a))
      {
        ans*=3;
      }
      else if('s' == tolower(a))
      {
        ans*=3;
      }
      else
        ans*=2;
    }

    printf("%d\n", ans );
  }

  return 0;
}
