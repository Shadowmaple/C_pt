#include <stdio.h>

int n;
int num[81];
int a[9] = {0};

void sort(int x)
{
	if (x == n) {
		for (int j =0; j < n; j++)
			printf("%d ", num[j]);
		putchar('\n');
	}
	else
		for (int i=0; i < n; i++) {
			if (a[i] ==0) {
				a[i] = 1;
				num[x] = i+1;
				sort(x+1);
				a[i] = 0;
			}
		}
}

int main()
{

	scanf("%d", &n);

	sort(0);

	return 0;
}
