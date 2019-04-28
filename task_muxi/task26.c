#include <stdio.h>

int fa(int a, int b)
{
	int c;
	if (a < b) {
		c = a;
		a = b;
		b = c;
	}
	while (a % b) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;

}

int main()
{
	int m, n;
	
	while (scanf("%d%d", &m, &n) != EOF) {
		int factor= fa(m, n);
		printf("%d\n", m*n/factor);
	}
}
