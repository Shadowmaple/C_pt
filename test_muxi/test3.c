#include <stdio.h>

int main()
{
	int sum=0, x, y, P, Q;

	scanf("%d %d", &x, &y);
	for (P =x; P <= y; P +=x) {
		Q = x * y / P;
		int ch = 1;
		if (x*y % P==0 && Q % x ==0) {
			for (int i = Q; i < y; i++)
				if (i % P == 0 && i % Q ==0) {
					ch = 0;
					break;
				}
			if (ch)
				sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}
