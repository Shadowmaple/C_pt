#include <stdio.h>
#include <math.h>

int fuc(int n, char A, char B, char C)
{
	if (n==1)
		printf("1 from %c to %c\n", A, C);
	else {
		fuc(n-1, A, C, B);
		printf("%d from %c to %c\n", n, A, C);
		fuc(n-1, B, A, C);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int x = pow(2,n);
	printf("%d\n", x-1);
	fuc(n, 'A','B','C');
	return 0;
}
