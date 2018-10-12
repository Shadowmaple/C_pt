#include<stdio.h>

int main()
{
	int a[100][100],b,c;
	do {
		scanf("%d", &b);
		if (b <= 2) puts("必须大于等于3！");
	} while (b <=2);

	for (int i=0; i<b; i++)
	{
		for (int j=0; j<b;j++)
			scanf("%d", &a[i][j]);

	}

	return 0;
}
