#include <stdio.h>

int main()
{
	int a, b = 1;
	printf("正整数：");
	scanf("%d", &a);
	while (a > 0)
	{
		switch(b % 2)
		{
			case 1: putchar('+'); break;
			default : putchar('-'); break;
		}
		++b;
		--a;
	}
	putchar('\n');
        return 0;
}
