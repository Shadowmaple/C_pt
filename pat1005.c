#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	int a[n], b[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	for (int i=0; i<n; i++) {
		if (!b[i])
			continue;
		while (a[i]!=1) {
			if (a[i]%2)
				a[i] =(3*a[i]+1)/2;
			else
				a[i] /=2;
			for (int j=0; j<n; j++)
				if (b[j]==a[i]) {
					b[j] = 0;
					break;
				}
		}
	}
	//获取关键数并取得总数
	int count =0;
	for (int i=0; i<n; i++) {
		if (!b[i])
			continue;
		a[count++] = b[i];
	}
	//排序并打印
	for (int i=0; i<count; i++) {
		int k = i;
		for (int j=i+1; j<count; j++) {
			if (a[j]>a[k])
				k = j;
		}
		if (k!=i) {
			int sw = a[i];
			a[i] = a[k];
			a[k] = sw;
		}
		printf("%d", a[i]);
		if (i!=count-1)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
