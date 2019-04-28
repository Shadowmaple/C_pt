#include <stdio.h>

int gc(int a, int b)
{
	int x;

	while (b != 0) {
		x=a % b;
		a = b;
		b = x;
	}

	return a;
}
int main()
{
	int a, b, c, d;

	do {	
		puts("Please enter two postive integer:");
		scanf("%d", &a);
		scanf("%d", &b);
		if (a <= 0 || b <= 0) puts("error!");
		if (a == b) puts("MUST DIFFERENT!");
	} while (a <= 0 || b <= 0 || a == b);
	
	if (a < b) {d = a; a = b; b = d;}

	c = gc(a,b);
	printf("%d\n", c);

	return 0;
}
