#include <stdio.h>

int main()
{
	int a, b, max, min, sum=0, i;
	puts("请输入两个整数。");
	printf("整数a："); scanf("%d",&a);
	printf("整数b："); scanf("%d",&b);
	max = (a > b)? a:b;
	min = (a < b)? a:b;
	i = min;

	do {
		sum+= i;
		++i;
	} while (i <= max);
	
	printf("大于等于%d小于等于%d的所有整数的和是%d。\n",
			min, max, sum);

        return 0;
}

