#include <stdio.h>

int main()
{
	int a[100],n;
	printf("输入个数：");
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d", &a[i]);

	for (int i = 0;i < n;i++)
		printf("%d ", a[n-i-1]);
	putchar('\n');
	return 0;

}
