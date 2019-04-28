#include <stdio.h>

void multiply(int a[][100], int b[], int line)
{
	int pr[line-1];
	for (int i=0; i < line; i++) {
		pr[i] = 1;
		for (int j =0; j < b[i]; j++) {
			if (a[i][j] % 2 == 1)
				pr[i] *= a[i][j];
		}
		printf("%d\n", pr[i]);
	}
}

int main()
{
	int a[100][100], b[100], n;
	int line = 0;
	int check;
	/*line代表行数，b[]代表元素个数*/

	do {
		check = 'F';
		scanf("%d", &n);
		if (n != 0) {
			for (; b[line] < n; b[line]++) {
				scanf("%d", &a[line][b[line]]);
			}

			for (int i=0; i < b[line]; i++)
				if (a[line][i] % 2 == 1) check = 'T';

			if (check == 'F') puts("error!");
			else line++;
		}
	} while (n != 0);
	/*输入0结束输入*/

	multiply(a, b, line);

	return 0;
}
