#include <stdio.h>

int main ()
{
	int n;
	scanf("%d", &n);
	int a[40] = {1,1,2,3};
	if (n>4) {
		int m=5;
		while (m<=n){
			a[m-1] = a[m-2]+a[m-3];
			m++;
		}
	}
	printf("%d\n", a[n-1]);

	return 0;
}
