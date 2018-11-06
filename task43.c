#include <stdio.h>

int main()
{
	int M, N, A, B, X;
	scanf("%d%d%d%d%d", &M, &N, &A, &B, &X);
	int a[M][N];
	for (int i=0; i < M; i++) {
		for (int j=0; j < N; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] >= A && a[i][j] <= B)
				a[i][j] = X;
		}
	}
	for (int i=0; i < M; i++) {
		for (int j=0; j < N; j++) {
			printf("%03d", a[i][j]);
			if (j != N-1) putchar(' ');
		}
		putchar('\n');
	}

	return 0;
}
