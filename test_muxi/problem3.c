#include<stdio.h>

int main()
{
	int b,c;
	do {
		scanf("%d", &b);
		if (b <= 2) puts("必须大于等于3！");
	} while (b <=2);

	int a[b][b];
	for (int i=0; i<b; i++)
	{
		for (int j=0; j<b; j++)
			scanf("%d", &a[i][j]);
	}

	for (c=1; c<=(b+1)/2; c++) {
		for (int y=c; y<=b-c+1; y++) {
			if (y==c || y==b-c+1) {
				for (int x =c; x<=b-c+1;x++)
					printf("%d ", a[y-1][x-1]);
			}
			else {
				for (int x=c; x<=b-c+1; x++) {
					if (x==b-c+1 || x==c)
					       	printf("%d ", a[y-1][x-1]);
					else printf("  ");
				}
			}
			putchar('\n');
		}
		if (c != (b+1)/2) putchar('\n');
	}
	return 0;
}
