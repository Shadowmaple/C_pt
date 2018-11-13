#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	if (n==0 || n==1) {
		puts("\\n");
		return 0;
	}
	int check =1;
	for (int i=2; i < n; i++)
		if (!(n % i)) {
			check=0;
			break;
		}
	if (check) puts("\\t");
	else puts("\\n");

	return 0;
}
