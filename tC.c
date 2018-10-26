#include <stdio.h>

int main()
{
	int n, sum = 0;
	int co = 0;
	int a[300];

	scanf("%d", &n);

	for (int num = 1; num <= n; num++) {
		if (num % 3 != 0 && num % 5 != 0) {
			int k = num;
			int ch = 'T';
			while (k / 10) {
				if (k % 10 == 3 || k % 10 == 5) {
					ch = 'F';
					break;
				}
				else
					k /= 10;
			}
			if (ch == 'T')
				a[co++] = num;
		}
	}

	for (int i = 0; i < co; i++)
		sum += a[i]*a[i];
	printf("%d\n", sum);
	return 0;
}
