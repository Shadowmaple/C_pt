#include <stdio.h>
#include <math.h>

int main()
{
	int m, n;

	scanf("%d%d", &m, &n);
	int a[n], sum=0;
	for (int i = 1; sum-1 <= n; i++) {
		int check=1;
		for (int j =2; j <= sqrt(i); j++) {
			if (!(i % j)) {
				check = 0;
				break;
			}
		}
		if (check)
			a[sum++] = i;
	}

	for (int i = m; i <= n; i++) {
		printf("%d", a[i]);
		if ((i-m+1) % 10 == 0 || i == n)
			putchar('\n');
		else
			putchar(' ');
	}
	return 0;
}
