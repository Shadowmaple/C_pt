#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);

	while (T--) {
		int m, n, x, y;
		scanf("%d%d%d%d", &m, &n, &x, &y);
		int num[m][n];
		for (int i=0; i < m; i++) {
			for (int j=0; j < n; j++)
				scanf("%d", &num[i][j]);
		}
		int max=0;
		for (int a=0; a < m-x+1; a++){
			for (int b=0; b < n-y+1; b++) {

				int sum=0;
				for (int i=a, step1=0; step1 < x; step1++, i++) {
					for (int j=b, step2=0; step2 < y; step2++, j++) {
						sum += num[i][j];
					}
				}	
				max = (max > sum) ? max:sum;

			}
		}
		printf("%d\n", max);
	}
	return 0;
}
