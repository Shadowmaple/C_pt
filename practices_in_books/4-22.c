#include <stdio.h>

int main()
{
	int a,b,c;
	puts("让我们来画一个长方形。");
	printf("一边："); scanf("%d",&a);
	printf("另一边："); scanf("%d",&b);

	if (a == b) puts("您输入的是正方形！\a");
	else {
		if (a < b) 
		{c=a; a=b; b=c;}

		for (int i=1; i <= b; i++)
		{
			for (int j=1; j<=a; j++)
				putchar('*');
			putchar('\n');
		}
	}

	return 0;
}
