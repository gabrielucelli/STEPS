#include <stdio.h>
#include <string.h>

#define MIN(x,y) (x<y? x : y)

int posicoes[3][2];
char direcoes[3];
int tartarugas_capturadas[3];

int pegar_tartaruga(int* x0, int* y0, int x, int y, char direcao, int tempo)
{
  for(int i=0; i<tempo; i++)
  {
    if(direcao == 'D')
    {
      x++;
    }
    if(direcao == 'C')
    {
      y++;
    }
  }

  int cont = 0;

  while(*x0 != x || *y0 != y)
  {

    cont++;

    if(direcao == 'D')
    {
      x++;
    }
    if(direcao == 'C')
    {
      y++;
    }

    if(*x0 == x)
    {
      if(*y0 > y)
      {
        if(((*y0)-=2) < y)
        {
          *y0 = y;
          return cont;
        }
      }
      else
      {
        if(((*y0)+=2) > y)
        {
          *y0 = y;
          return cont;
        }
      }
    }
    else if(*y0 == y)
    {
      if(*x0 > x)
      {
        if(((*x0)-=2) < x)
        {
          *x0 = x;
          return cont;
        }
      }
      else
      {
        if(((*x0)+=2) > x)
        {
          *x0 = x;
          return cont;
        }
      }
    }
    else if(*x0 > x && *y0 > y)//diagonal
    {
      (*x0)--; (*y0)--;
    }
    else if(*x0 < x && *y0 < y)//diagonal
    {
      (*x0)++; (*y0)++;
    }
    else if(*x0 > x && *y0 < y)//diagonal
    {
      (*x0)--; (*y0)++;
    }
    else if(*x0 < x && *y0 > y)//diagonal
    {
      (*x0)++; (*y0)--;
    }

      //printf("x0 = %d y0 = %d | x = %d y = %d | direcao = %c\n", *x0, *y0, x, y, direcao);
  }

  //printf("tempo = %d\n\n", cont);
  return cont;
}

int main()
{
  int x0, y0;

  while(scanf("%d %d", &x0, &y0) && x0!=0 && y0!=0)
  {
    for(int i=0; i<3; i++)
    {
      scanf("%d %d %c", &posicoes[i][0], &posicoes[i][1], &direcoes[i]);
    }

    int tempo;
    int menor_tempo;

    int aux_x0 = x0;
    int aux_y0 = y0;

    // 0 1 2
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    menor_tempo = tempo;
    x0 = aux_x0;
    y0 = aux_y0;

    // 0 2 1
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    menor_tempo = MIN(menor_tempo, tempo);
    x0 = aux_x0;
    y0 = aux_y0;

    // 1 0 2
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    menor_tempo = MIN(menor_tempo, tempo);
    x0 = aux_x0;
    y0 = aux_y0;

    // 1 2 0
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    menor_tempo = MIN(menor_tempo, tempo);
    x0 = aux_x0;
    y0 = aux_y0;

    // 2 0 1
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    menor_tempo = MIN(menor_tempo, tempo);
    x0 = aux_x0;
    y0 = aux_y0;

    // 2 1 0
    tempo = 0;
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[2][0], posicoes[2][1], direcoes[2], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[1][0], posicoes[1][1], direcoes[1], tempo);
    tempo+=pegar_tartaruga(&x0, &y0, posicoes[0][0], posicoes[0][1], direcoes[0], tempo);
    menor_tempo = MIN(menor_tempo, tempo);

    printf("%d\n", menor_tempo );

  }

  return 0;
}
