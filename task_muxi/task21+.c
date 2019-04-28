#include <stdio.h>

int a[1001] = {0};
int count(int n)
{
	a[2] = 2;
	a[3] = 2;
	a[4] = 6;
	for (int i=5; i <= n; i++)
		a[i] = (a[i-1]+a[i-2]*2) % 10000;
	return a[n];
}

int main()
{
	int n, result;
	while(scanf("%d", &n) != EOF && n != 0) {
		result = count(n);	
		printf("%d\n", result);
	}
	return 0;
}
