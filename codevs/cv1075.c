#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	int sum=0;
	for (int i=0; i < n; i++) {
		scanf("%d", &a[i]);
		int check=1;
		for (int j=0; j < sum; j++)
			if (a[i] == b[j]) {
				check = 0;
				break;
			}
		if (check)
			b[sum++] = a[i];
	}
	printf("%d\n", sum);
	for (int i=0; i < sum; i++) {
		int k = i;
		for (int j=i+1; j < sum; j++) {
			if (b[k] > b[j]) {
				k = j;
			}
		}
		if (k != i) {
			int swp = b[i];
			b[i] = b[k];
			b[k] = swp;
		}
		printf("%d", b[i]);
		if (i!=sum-1)
			putchar(' ');
		else putchar('\n');
	}
	return 0;
}
