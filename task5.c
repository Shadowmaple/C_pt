#include <stdio.h>
#include <limits.h>
#include <math.h>

int main()
{
	int a[INT_MAX], n = 1;
	int check;

	a[0] = 1;

	for (int i = 2; i < 101; i++) {
		check = 'T';
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				check = 'F';
				break;
			}
		}
		if (check == 'T') a[n++] = i;
	}

	for (int i = 0; i < n; i++) {
		printf("%2d ", a[i]);
		if ((i+1) % 5 == 0) putchar('\n');
		if (i == n-1 && i % 4 != 0) putchar('\n');
	}

	return 0;
}
