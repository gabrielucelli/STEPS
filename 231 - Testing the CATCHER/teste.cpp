#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int a[1000+5];
int n;

int lis( int arr[], int n )
{
   int *lis, i, j, max = 0;
   lis = (int*) malloc ( sizeof( int ) * n );

   /* Initialize LIS values for all indexes */
   for ( i = 0; i < n; i++ )
      lis[i] = 1;

   /* Compute optimized LIS values in bottom up manner */
   for ( i = 1; i < n; i++ )
      for ( j = 0; j < i; j++ )
         if ( arr[i] <= arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;

   /* Pick maximum of all LIS values */
   for ( i = 0; i < n; i++ )
      if ( max < lis[i] )
         max = lis[i];

   /* Free memory to avoid memory leak */
   free( lis );

   return max;
}

int main()
{
  int t = 0;
  int i = 0;

  while(1)
  {
    i = 0;

    while(scanf("%d", &a[i]) && a[i++] != -1) ;

    n = i-1;

    if(a[0] == -1)
      return 0;

    n = i-1;

    printf("Test #%d:\n", ++t);
    printf("\tmaximum possible interceptions: %d\n\n", lis(a,n) );


  }

  return 0;
}
