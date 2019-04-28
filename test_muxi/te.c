#include <stdio.h>
int main()
{
	int n;
	int a[30][100]={0};

	while (scanf("%d", &n) !=EOF) {
		if (n < 1 || n >30)
			break;
		else {
			for (int i=0; i < n; i++) {
				for (int j=0; j < i+1; j++) {
					if (i == 0 || j == 0)
						a[i][j] = 1;
					else {
						a[i][j] = a[i-1][j-1] + a[i-1][j];
					}
				}
			}

			for (int i=0; i < n; i++) {
				for (int j = 0; j < i+1; j++) {
					printf("%d ", a[i][j]);
				}
				putchar('\n');
			}
			putchar('\n');
		}
	}
}
