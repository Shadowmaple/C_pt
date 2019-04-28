#include <stdio.h>
int sum = 1;

void ha(int n, int m)
{
	if (m / 2)
	{
		for (int i =1; i <= m/2; i++) {
			int k = n;
			sum++;
			ha(k, i);
		}
	}

}

int main()
{
	int n;

	scanf("%d", &n);

	ha(n, n);

	printf("%d\n", sum);

	return 0;
}
