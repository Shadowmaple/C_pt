#include <stdio.h>

void pr(double a[][100], int b[], int s)
{
	for (int i=0; i < s; i++) {
		double max = a[i][0], min= a[i][0];
		double sum=0;
		for (int j=1; j < b[i]; j++) {
			max = (max > a[i][j])? max : a[i][j];
			min = (min < a[i][j])? min : a[i][j];

		}
		for (int j=0; j < b[i]; j++) {
			if (max == a[i][j]) max= a[i][j] = 0;
			if (min == a[i][j]) min= a[i][j] = 0;
		}
		for (int j=0; j < b[i]; j++) {
			sum += a[i][j];
		}
		sum = sum / (b[i]-2);

		printf("%.2lf\n", sum);
	}
	
}

int main()
{
	int b[100], n, line=0;
	double a[100][100];

	do {
		scanf("%d", &n);
		if (n > 2 && n <= 100) {

			for (; b[line] < n; b[line]++) {
				scanf("%lf", &a[line][b[line]]);

			}
			line++;
		} else if (n != 0) {
			puts("error!");
		}
	} while (n != 0);

	pr(a, b, line);
	return 0;
}
