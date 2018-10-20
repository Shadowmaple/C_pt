#include <stdio.h>

int main()
{
	int n, m, ck;
	double a[50][5], b[50], c[5];

	do {
		ck=0;
		scanf("%d %d", &n, &m);
		if (n > 50 ||n < 1 || m < 1 || m > 5) {
			puts("error!");
			ck = 1;
			continue;
		}
		for (int i=0; i < n; ++i)
			for (int j=0; j < m; ++j)
				scanf("%lf", &a[i][j]);
	} while (ck);

	//计算个人平均成绩
	for (int i=0; i < n; ++i) {
		for (int j=0; j < m; ++j)
			b[i] += a[i][j];
		b[i] /= m;
	}
	
	//计算各科平均成绩
	for (int i=0; i < m; ++i) {
		for (int j=0; j < n; ++j)
			c[i] += a[j][i];
		c[i] /= n;
	}
	
	//输出个人平均成绩
	for (int i=0; i < n; ++i)
		printf("%.2lf ", b[i]);
	putchar('\n');

	//输出各科平均成绩
	for (int i=0; i < m; ++i)
		printf("%.2lf ", c[i]);

	int sum=0;
	for (int i=0, j; i < n; ++i) {
		for (j=0; j < m; ++j)
			if (a[i][j] < c[j]) break;
		if (j == m) sum++;
	}
	printf("\n%d\n", sum);
	return 0;
}
