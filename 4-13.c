#include <stdio.h>

int main()
{
	int n, sum= 0;
	printf("n的值：");
	scanf("%d", &n);

	if(n < 1) puts("n的值必须为大于等于1的整数！\a");
	else {
		for (int i = 1; i <= n; i++)
			sum += i;
		printf("1到%d的和为%d。\n", n, sum);
	}
        return 0;
}
