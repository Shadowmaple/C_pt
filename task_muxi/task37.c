#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	char num[n][15];
	int machine[n], test[n];
	for (int i=0; i < n; i++) {
		scanf("%s %d %d", num[i], &machine[i], &test[i]);
	}
	int no;
	scanf("%d", &no);
	int seat[no];
	for (int i =0; i < no; i++) {
		int a;
		scanf("%d", &a);
		for (int j=0; j < n; j++) {
			if (machine[j] == a) {
				seat[i] =j;
				break;
			}
		}
	}
	for (int i=0; i < no; i++)
		printf("%s %d\n", num[ seat[i] ], test[ seat[i] ]);

	return 0;
}
