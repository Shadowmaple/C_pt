#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		long A, B;
		scanf("%ld%ld", &A, &B);
		if (A % B)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
