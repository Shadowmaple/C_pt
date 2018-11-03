#include <stdio.h>

int main()
{
	int m, n;
	scanf("%d", &m);
	while (m--) {
		scanf("%d", &n);
		double num[n], max =0;
		for (int i=0; i < n; i++) {
			scanf("%lf", &num[i]);
			max = (max > num[i])? max:num[i];
		}
		printf("%.2f\n", max);
	}
	return 0;
}
