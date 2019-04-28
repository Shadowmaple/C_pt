#include <stdio.h>

int main()
{
	int n[100], m[100], line=0, a[100][100];

	do {
		scanf("%d %d", &n[line], &m[line]);
		for (int i=0; i < n[line]; ++i) {
			scanf("%d", &a[line][i]);
		}
		if (!(n[line]==0 && m[line]==0)) line++;
		else break;
	
	
	} while (1);

	for (int i=0; i < line; i++) {
		for (int j=0; j < n[i]; j++) {
			for (int k = n[i]-1, w; k > j; k--)
				if (a[i][j] < a[i][k]) {
					w = a[i][j];
					a[i][j] = a[i][k];
					a[i][k] = w;
				}

		}
	}

	for (int i =0, j; i < line; i++) {
		for (j=0; j < m[i]; j++)
			printf("%d ", a[i][j]);
		for (; j < n[i]; j++)
			if (a[i][j] == a[i][j-1])
				printf("%d ", a[i][j]);
			else break;
		putchar('\n');
	}


	return 0;
}
