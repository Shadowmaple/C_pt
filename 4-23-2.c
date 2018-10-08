#include <stdio.h>

int main()
{
	int len, j;
	puts("生成直角在右上方的等腰直角三角形。");
	do {
		printf("短边：");
		scanf("%d", &len);

		if (len < 2) puts("必须为大于1的整数！\a");
	} while (len < 2);

	for (int i=1; i<= len; i++)
	{
		for (j=1; j<i; j++)
			putchar(' ');
		for (j=1; j<=len-i+1; j++)
			putchar('*');
		putchar('\n');
	}
	return 0;
}
