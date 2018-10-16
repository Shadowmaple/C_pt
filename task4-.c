#include <stdio.h>

int gc(int a, int b)	/*求最小公倍数*/
{
	int x, y = a*b;

	while (b != 0) {
		x = a % b;
		a = b;
		b = x;
	}
	
	x = y / a;
	return x;
}

int main()
{
	int a, b, c;

	do {
		puts("please enter two postive integer:");
		scanf("%d", &a);
		scanf("%d", &b);
		if (a == b) puts("MUST DIFFERENT!");
		if (a <= 0 || b <= 0) puts("ERROR!");
	} while (a <= 0 || b <= 0 || a == b);

	if (a < b) {
		c = a;
		a = b;
		b = c;
	}

	c = gc(a, b);
	printf("%d\n", c);
	return 0;
}
