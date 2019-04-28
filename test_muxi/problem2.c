#include <stdio.h>

void pr(int a)
{

	printf("the number of prime number is %d.\n", a);
}

int main()
{
	int i,j,n[100],k,a,b;
	do {
		scanf("%d", &i);
		getchar();
		scanf("%d", &j);
		getchar();
		if (i <= 0 || j <= 0) puts("请输入正整数！\a");
		if (i == j) puts("请输入两个不等数！");
	} while (i <= 0 || j <= 0 || i == j);
	
	a = (i > j) ? i :j;
	b = (i > j) ? j :i;
	k=0;
	for (int i = b; i <= a;i++)
	{	
		int m;
		for (int j= 2;j < i;++j)
			if (i / j == 0) {m = 0;break;}
		if (m != 0) n[k++]=i;
	}

	for (int i=0,j=1; i<k; i++)
	{
		printf("%-4d", n[i]);
		if (j++%9 == 0) putchar('\n');
	}
	pr(k);
	return 0;
}
