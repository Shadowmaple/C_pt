#include <stdio.h>

int main()
{
	int a,b,c,min;
	puts("请输入三个整数：");
	scanf("%d%d%d",&a,&b,&c);
	
	min = (a < b) ? a:b;
	min = (min < c)? min:c;

	printf("最小的数是：%d\n", min);
	return 0;
}
