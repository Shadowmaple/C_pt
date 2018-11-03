#include <stdio.h>

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) {
		int A, B;
		scanf("%d%d", &A, &B);
		if (A % B)
			puts("NO");
		else
			puts("YES");
	}
	return 0;
}
