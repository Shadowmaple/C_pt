#include <stdio.h>
#include <string.h>

int main()
{
	char n[1000];
	scanf("%s", n);
	int a[10] = {0};

	for (int i=0; i < strlen(n); i++) {
		a[n[i] - '0']++;
	}
	for (int i =0; i <= 9; i++)
		if (a[i])
			printf("%d:%d\n", i, a[i]);
	return 0;
}
