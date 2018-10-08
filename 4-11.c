#include <stdio.h>

int main()
{
	int num;

	do {
		printf("请输入一个正整数：");
		scanf("%d",&num);
	} while (num <= 0);

	printf("%d逆显示结果是", num);
	
	while (num > 0)
	{
		printf("%d", num % 10);
		num/= 10;
	}
	puts("。");
        return 0;
}
