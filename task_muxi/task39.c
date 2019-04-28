#include <stdio.h>

int main()
{
	int n;
	while (1) {
		scanf("%d", &n);
		if (!n) break;
		int tea[n];
		for (int i=0; i < n; i++)
			scanf("%d", &tea[i]);

		int money[6] = {100, 50, 10, 5, 2, 1};
		int sum =0;
		for (int i=0; i < n; i++) {
			for (int j=0; j < 6; j++) {
				if (tea[i] / money[j]) {
					sum += tea[i] / money[j];
					tea[i] %= money[j];
				}
				if (!tea[i]) break;
			}	
		}

		printf("%d\n", sum);
	}

	return 0;
}
