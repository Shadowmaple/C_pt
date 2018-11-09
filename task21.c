#include <stdio.h>

int count(int n, int x)
{
	if (n == 1) return 1;
	int sum =0;
	for (int i=0; i < 3; i++) {
		if (i == x) continue;
		if (n == 2 && i == 0) continue;
		int y = n-1;
		sum += count(y, i);
	}
	return sum;
}

int main()
{
	int n;
	int x = 0, result;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		result = count(n, x);
		printf("%d\n", result % 10000);
	}

	return 0;
}
