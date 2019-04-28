#include <stdio.h>

int main()
{
	int n, sum=0;

	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		int m;
		scanf("%d", &m);
		sum += m;
	}

	printf("%d\n", sum);

	return 0;
}
