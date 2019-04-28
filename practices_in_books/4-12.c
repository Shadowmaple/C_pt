#include <stdio.h>

int main()
{
	int n, i=0;

	do {
		printf("请输入一个正整数：");
		scanf("%d", &n);
	} while (n <= 0);

	printf("%d的位数是", n);

	while (n > 0)
	{
		n/=10;
		++i;
	}
	printf("%d。\n",i);
        return 0;
}

