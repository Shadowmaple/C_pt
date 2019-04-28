#include <stdio.h>
int main()
{
	int a,b,no;
	char i;

	do {
		printf("请输入一个整数：");
		scanf("%d",&no);
		getchar();

		if (no == 0) puts("该整数为0。");
		else if (no > 0) puts ("该整数为整数。");
		else puts("该整数为负数。");

		printf("是否继续？<y/n>：");
		i = getchar();
	} while (i == 'y');
	
	return 0;
}
