#include <stdio.h>

int main()
{
	int n, min, max, a[100];

	scanf("%d", &n);
	for (int i =0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	min = max = a[0];
	for (int i=1; i < n; i++) {
		max = (max > a[i])? max : a[i];
		min = (min < a[i])? min : a[i];
	}

	printf("%d %d\n", min, max);
	return 0;
}
