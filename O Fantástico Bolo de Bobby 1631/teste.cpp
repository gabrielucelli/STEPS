#include <stdio.h>
#include <math.h>

struct point {
  double x,y;
  point(double x = 0, double y = 0): x(x), y(y) {}
  point operator +(point q){ return point(x + q.x, y + q.y); }
  point operator -(point q){ return point(x - q.x, y - q.y); }
  point operator *(double t){ return point(x * t, y * t); }
  point operator /(double t){ return point(x / t, y / t); }
  double operator *(point q){ return x * q.x + y * q.y; }
  double operator %(point q){ return x * q.y - y * q.x; }

};

typedef point vetor;
double norma(vetor v){ return hypot(v.x, v.y); }

vetor projecao(vetor v, vetor w){ /* proj de v em w */
double alfa = (v*w)/(w*w);
return w*alfa;
}

struct reta {
  point ini,fim;
  reta(){}
  reta(point ini, point fim): ini(ini), fim(fim) {}
};

struct eq_reta {
  double A,B,C; /* Ax + By + C = 0 */
  void init(reta p)
  {
    point aux = p.ini - p.fim;
    A = aux.y;
    B = -aux.x;
    C = -A*p.ini.x - B*p.ini.y;
  }
  eq_reta(reta p){ init(p); }

  int pertence(point a)
  {
    if(A*a.x + B*a.y + C == 0)
      return 1;
    else
      return 0;
  }
  double dominio(double y)
  {
    return (-1)*(B*y + C)/A;
  }
};

double distPR(point p, reta r){
  vetor v = p - r.ini;
  vetor w = r.fim - r.ini;
  vetor proj = projecao(v,w);
  /* (proj+r.ini) eh o ponto mais proximo de p,
  e que pertencente aa reta r */
  /* para segmentos de reta
  *
  * if( !between(proj+r.ini, r) )
  * return min( norma(p-r.ini), norma(p-r.fim) );
  */
  return norma(v - proj);
};

int main()
{
  int cases;
  double x, y;
  double ans = 9999999;

  while(scanf("%d", &cases) && cases != 0)
  {
    point pontos[cases];

    for(int i=0; i<cases; i++)
    {
      scanf("%lf %lf", &x, &y);
      pontos[i].x = x;
      pontos[i].y = y;
      //printf("%lf %lf\n",   pontos[i].x, pontos[i].y );
    }


    for(int i=0; i<cases; i++)
    {
      for(int j=i+1; j<cases; j++)
      {
        reta reta_aux(pontos[i], pontos[j]);
        eq_reta eq_aux(reta_aux);

        double dir = 0;
        double esq = 0;

        for(int l = 0; l<cases; l++)
        {
          if(l != i && l != j && !eq_aux.pertence(pontos[l]))
          {
            if(eq_aux.A == 0)
            {
              if(pontos[l].y > 0)
              {
                dir += distPR(pontos[l], reta_aux);
              }
              else
                esq += distPR(pontos[l], reta_aux);
            }
            else if(eq_aux.dominio(pontos[l].y) < pontos[l].x)
            {
              //esquerda
              esq += distPR(pontos[l], reta_aux);
            }
            else
            {
              //direita
              dir += distPR(pontos[l], reta_aux);
            }
          }
        }

        //printf("dir = %lf esq = %lf\n", dir, esq );

        if(fabs(esq - dir) < ans)
          ans = fabs(esq - dir);
      }
    }

    printf("%.3lf\n", ans );
  }

  return 0;
}
