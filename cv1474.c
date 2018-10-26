#include <stdio.h>

int main()
{
	char a[17] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	int n, m;

	scanf("%d %d", &n, &m);
	char num[100]= {0};
	int sum=0;
	while (n > 0) {
		num[sum] = a[n % m];
		n /= m;
		sum++;
	}
	for (int i =sum-1; i >=0; i--)
		putchar(num[i]);

	putchar('\n');
	return 0;

}
