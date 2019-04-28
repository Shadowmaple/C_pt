#include <stdio.h>

int main()
{
	int a[100],n;
	printf("输入个数：");
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d", &a[i]);

	for (int i = 0;i <= n/2;i++){
		int x;
		x = a[i];
		a[i] = a[n-i-1];
		a[n-i-1] = x;
	}

	for (int i =0;i < n;i++)
		printf("%d ", a[i]);
	putchar('\n');
	return 0;

}
