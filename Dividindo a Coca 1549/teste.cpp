#include <stdio.h>

#define PI 3.14159265359

double n, l, b, B, H;

double volume(double b1, double B1, double h)
{
  return PI*h/3*(B1*B1 + B1*b1 + b1*b1);
}

double bin_search(double inf, double sup)
{
  //printf("inf = %lf sup = %lf\n", inf, sup );
  double base = b + (B-b)/H*(inf+sup)/2;
  //printf(">> %lf\n", base );
  //printf("h = %lf volume = %lf\n", (inf+sup)/2,volume(b, base, (inf+sup)/2)  );
  //printf("\n");

  if(volume(b, base, (inf+sup)/2) > l/n - 0.0000001 && volume(b, base, (inf+sup)/2) < l/n + 0.0000001 )
  {
    return (inf + sup)/2;
  }
  else if(volume(b, base, (inf+sup)/2) > l/n)
  {
    return bin_search(inf, (inf+sup)/2);
  }
  else if(volume(b, base, (inf+sup)/2) < l/n)
  {
    return bin_search((inf+sup)/2, sup);
  }
}

int main()
{
  int cases;

  scanf("%d", &cases);
  for(int i=0; i< cases; i++)
  {
    scanf("%lf %lf", &n, &l);
    scanf("%lf %lf %lf", &b, &B, &H);

    //double h = 3*l/PI/n*(1/(B*B + B*b + b*b));
    //printf("%.2lf\n", h);
    //printf("%lf\n", volume(b,B,2.4) );
    //printf("%lf\n", volume(b, 5.3, 2.4) );
    printf("%.2lf\n", bin_search(0, H) );
  }
  return 0;
}
