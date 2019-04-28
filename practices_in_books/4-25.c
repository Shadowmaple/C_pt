#include<stdio.h>

int main()
{
	int n;
	puts("让我们来画一个向下的金字塔。");
	do {
		printf("金字塔有几层：");
		scanf("%d", &n);
		if (n < 2) puts("金字塔不存在！\a");
	} while(n < 2);

	for (int i =1; i<=n; ++i)
	{
		int j;
		for (j =1; j<=i-1; ++j)
			putchar(' ');
		for (j =1; j<=(n-i)*2+1; ++j)
			printf("%d", i % 10);
		putchar('\n');
	}
	return 0;
}
