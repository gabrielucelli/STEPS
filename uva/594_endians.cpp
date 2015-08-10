#include <stdio.h>
#include <stdlib.h>


unsigned long EndianSwap32(unsigned long x)
{

    unsigned long y=0;

    y += (x & 0x000000FF)<<24;

    y += (x & 0xFF000000)>>24;

    y += (x & 0x0000FF00)<<8;

    y += (x & 0x00FF0000)>>8;

    return y;

}

int main()
{
	int a;
	while(scanf("%d", &a)!=EOF)
	{
		printf("%d converts to %d\n", a, EndianSwap32(a));
	}
	
	return 0;
}