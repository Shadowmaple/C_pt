#include <stdio.h>

int main() {
	int n, count = 2;
	scanf("%d", &n);
	int a[n][n];
	int i,j;
	i = j = n/2;
	a[i][j] = 1;
	for (int m=1; m<=n/2; m++) {
		for (int h=1; h<=2*m-1; h++)
			a[i][++j] = count++;
		
		for (int h=1; h<=2*m-1; h++)
			a[--i][j] = count++;
		
		for (int h=1; h<=2*m; h++)
			a[i][--j] = count++;

		for (int h=1; h<=2*m; h++)
			a[++i][j] = count++;
	}
	for (int h=1; h<=n-1; h++)
		a[i][++j] = count++;

	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}

	int sum =0;
	for (int i=0; i<n; i++)
		sum +=a[i][i]+a[i][n-1-i];
	printf("%d\n", sum-1);

	return 0;
}
