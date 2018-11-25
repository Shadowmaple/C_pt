#include <stdio.h>

int gcd(int a, int b) {
	if (!b)
		return a;
	int c = a % b;
	a = b;
	b = c;
	return gcd(a,b);
}

int main() {
	int A, B;
	scanf("%d%d", &A,&B);
	int n = gcd(A,B);
	printf("%d\n", n);
	return 0;
}
