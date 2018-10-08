#include <stdio.h>

int main()
{
	int i;
	printf("正整数：");
	scanf("%d", &i);

	while (i > 0)
	{
		putchar('*');
		--i;
	}
	putchar('\n');
	return 0;
}
