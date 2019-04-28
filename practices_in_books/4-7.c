#include <stdio.h>

int main()
{
	int i, no, j;

	printf("请输入一个整数：");
	scanf("%d",&no);
	i = 2;
	j = i;

	while (j <= no)
	{
		printf("%d ",i);
		i*= 2;
		j = i;
	}
	if (no >= 2) putchar('\n');
        return 0;
}
