#include <stdio.h>

void sort(int a[], int left, int right);

int main()
{
	int n;

	scanf("%d", &n);
	int a[n];

	if (n > 0 && n <= 100000) {
		for (int i=0; i < n; i++) {
			scanf("%d", &a[i]);
		}

/*		for (int i=0, w; i < n-1; i++) {
			for (int j=i+1; j < n; j++) {
				if (a[i] > a[j]) {
					w = a[i];
					a[i] = a[j];
					a[j] = w;
				}	
			}
		}
*/
		sort(a, 0, n-1);


		for (int i=0; i < n; ++i)
			printf("%d ", a[i]);
		putchar('\n');

	} else puts("error!");

	return 0;
}

void sort(int a[], int left, int right)
{
	if (left >= right)
		return ;

	int i = left, j = right;
	int k = a[i];

	while (i < j) {
		for (; a[j] >= k && i < j; j--) ;

		a[i] = a[j];

		for (; a[i] <= k && i < j; i++) ;

		a[j] = a[i];

		}

	a[i] = k;
	sort(a, left, i - 1);	
	sort(a, i +1, right);
}
