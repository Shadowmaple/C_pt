#include <stdio.h>

int main()
{
	int n;
	printf("请输入一个整数：");
	scanf("%d", &n);

	if (n <= 0) puts("必须为正整数！\a");
	else 
	{
		for (int i=1; i <= n; i++)
			switch (i % 10)
			{
				case 1: putchar('1'); break;
				case 2: putchar('2'); break;
				case 3: putchar('3'); break;
				case 4: putchar('4'); break;
				case 5: putchar('5'); break;
				case 6: putchar('6'); break;
				case 7: putchar('7'); break;
				case 8: putchar('8'); break;
				case 9: putchar('9'); break;
				case 0: putchar('0'); break;
			}
		putchar('\n');
	}
        return 0;
}
