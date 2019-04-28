#include <stdio.h>

int main ()
{
	int n, y;
	double m;

	scanf("%d %lf", &n, &m);
	int x;
	x = m * n /10;
	y = x % 10;

	if (y <= 9 && y > 4)
		x = x +10;
	x = x - y;

	printf("%d\n", x);
	return 0;
}
