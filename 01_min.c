#include <stdio.h>

int main (void)
{
	int i, n, a, b;
	b=0;
	scanf ("%d", &n);
	for (i=0; i<=n; i++)
	{
		scanf ("%d", &a);
		b = a+b;
	}
	printf ("%d", b);

}
