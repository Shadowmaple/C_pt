#include <stdio.h>

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
		for (int i=0; i<n; ++i) {
			int  g = a[i];
			int left = 0;
			int right = n-1;
			while(left <= right) {
				int mid = (left +right)/2;
				if (a[mid] > g)
					right = mid -1;
				else
					left = mid + 1;
			}
			for (int j=)
		
		
		
		}
		for (int i=0; i < n; ++i)
			printf("%d ", a[i]);
		putchar('\n');

	} else puts("error!");

	return 0;
}
