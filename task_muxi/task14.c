#include <stdio.h>
int main()
{
	int n, a[100];

	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i=0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i=1; i < n; i++) {
			if (a[i] < a[0]) {
				int swap = a[0];
				a[0] = a[i];
				a[i] = swap;
			}
		}
		for (int i=0; i < n; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
}
