#include <stdio.h>

int main()
{
	int h[2],k;
	printf("开始数值(cm)：");
	scanf("%d", &h[0]);
	printf("结束数值(cm)：");
	scanf("%d", &h[1]);
	printf("间隔数值(cm)：");
	scanf("%d", &k);

	for (int i=h[0]; i <= h[1]; i+=k)
		printf("%dcm\t%.2fkg\n", i, (i-100)*0.9);

        return 0;
}
