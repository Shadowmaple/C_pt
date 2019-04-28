#include <stdio.h>
#include <stdlib.h>

void sw(int a[][100], int s, int b[])
{
	for (int i=0; i < s; i++){
		for (int j=0; j<b[i]; j++)
			for (int k=j+1, h; k<b[i]; k++)
				if (abs(a[i][j]) < abs(a[i][k])) {
					h = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = h;
				}
	}

}

int main()
{
	int a[100][100], n, s=0, b[100];
	int check;
	/*s为行数，组数，从0开始；b[]为各组的元素个数*/

	do {
		scanf("%d", &n);
		if (n > 100 || n < 0) puts("ERROR!");
		else {
			for (; b[s] < n; ++b[s]) {
				scanf("%d", &a[s][ b[s] ] );

				for (int i=0; i < b[s]; i++)
					if ( abs( a[s][i] ) == abs( a[s][ b[s] ] ) ) {
						puts("error"); break;
					}
			}
			if (n != 0) s++;
		}
	} while (n != 0);

	sw(a, s, b);
	putchar('\n');

	for (int i=0; i < s; i++) {
		for (int j=0; j < b[i]; j++)
			printf("%d ", a[i][j]);
		putchar('\n');
	}

	return 0;
}
