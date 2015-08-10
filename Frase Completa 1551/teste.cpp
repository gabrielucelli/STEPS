#include <stdio.h>
#include <string.h>

int main()
{
  int alfabeto_num[26];
  //char c = 'a';

  //printf("%d\n", 'b' - 'a');

  //for(int i=0; i<26; i++)
  //{
  //  alfabeto[i] = c++;
  //}

  int cases;
  char frase[1050];

  scanf("%d\n", &cases);
  for(int i=0; i<cases; i++)
  {
    memset(alfabeto_num, 0, sizeof(alfabeto_num));

    scanf("%[^\n]\n", frase);

    for(int j=0; j<strlen(frase); j++)
    {
      if(frase[j] - 'a' >= 0 && frase[j] - 'a' < 26)
      {
        alfabeto_num[frase[j] - 'a']++;
      }
    }

    int cont =0 ;
    for(int j=0; j<26; j++)
    {
    //  printf("%d ", alfabeto_num[j] );
      if(alfabeto_num[j] != 0)
        cont++;
    }
  //printf("\n");

  //  printf("%d\n", cont);

    if(cont == 26)
      printf("frase completa\n" );
    else if(cont >= 13)
      printf("frase quase completa\n" );
    else
      printf("frase mal elaborada\n" );

  }

  return 0;
}
