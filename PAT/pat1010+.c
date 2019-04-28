#include <stdio.h>

int main()
{
	int flag=0;
	int m, n;
	while (scanf("%d %d", &m, &n) != EOF) {
		if (n!=0) {
			if (flag)
				printf(" %d", m*n);
			else {
				printf("%d", m*n);
				flag = 1;
			}
			printf(" %d", --n);
		}
	}
	if (!flag)
		puts("0 0");
	return 0;
}
