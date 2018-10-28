#include <stdio.h>

int main()
{
	int n, m;
	int a[100];

	while (scanf("%d %d", &n, &m) != EOF) {
	/*	do {
		scanf("%d %d", &n, &m);
		if (m ==0 && m == 0)
			 break;
		else {
	*/
			for (int i =0; i < n; i++)	
				scanf("%d", &a[i]);
		

		for (int i =0; i < n; i++ ) {
			if (a[i] > m) {
				for (int j = n; j > i; j--) {
					a[j] = a[j-1];
				}
				a[i] = m;
		
			}
		}
		for (int i =0; i <= n; i++)
			printf("%d ", a[i]);
		putchar('\n');
		}
//	} while (1);

//	return 0;
}

//https://vjudge.net/contest/265210#overview
