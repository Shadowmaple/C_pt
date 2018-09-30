#include <stdio.h>

int main()
{
	int h;
	printf("请输入您的身高：");
	scanf("%d" , &h );
	printf("您的标准体重是%.1f公斤。\a\n", (double) ( h-100 )* 0.9 );
	return 0;
}
