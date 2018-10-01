#include <stdio.h>

int main()
{
	int a,b;

	puts("请输入两个整数。");
	printf("整数A：");
	scanf("%d",&a );
	printf("整数B：");
	scanf("%d" , &b);

	if( a % b ) printf("B不是A的约数。\n");
	else puts("B是A的约数。")
		;
	return 0;
}
