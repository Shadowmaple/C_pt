#include <stdio.h>

int n, m;
void move(int m, int *a)
{
	int sw = a[n-1];
	for (int i=n-2; i>=0; i--)
		a[i+1] = a[i];
	a[0] = sw;
	m--;
	if (m>0)
		move(m, a);
}

int main()
{
	scanf("%d%d", &n, &m);
	int a[n];
	for (int i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	move(m, a);
	for (int i=0; i<n; i++) {
		printf("%d", a[i]);
		if (i!=n-1)
			putchar(' ');
		else
			putchar('\n');
	}
	return 0;
}
