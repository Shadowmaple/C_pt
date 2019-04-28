#include <stdio.h>

int main()
{
	int n, a[1000];

	scanf("%d", &n);
	for (int i=0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i=0; i < n; i++)
		putchar((char)(a[i]));	
	putchar('\n');
	return 0;
}
