#include <stdio.h>

int main()
{
	int a[10] = {0}, n;
	long A, B, C;

	scanf("%d", &n);
	for (int i=0; i < n; i++) {
		scanf("%ld%ld%ld", &A, &B, &C);
		if (A + B > C)
			a[i] = 1;
		else a[i] = 0;
	}

	for (int i=0; i < n; i++)
		if (a[i])
			printf("Case #%d: true\n", i+1);
		else
			printf("Case #%d: false\n", i+1);
	return 0;
}
