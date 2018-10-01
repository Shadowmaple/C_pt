#include <stdio.h>

int main()
{
	int a,b,c,min;
	puts("请输入三个整数：");
	scanf("%d%d%d",&a,&b,&c);
	min = a;

	if( min > b ) min = b;
	if( min > c ) min = c;
	
	printf("最小的数是：%d\n", min);
	return 0;
}
