#include <stdio.h>

int main()
{
	int N;
	scanf("%d", &N);
	int sch[N];
	int n, m;
	int count =N;
	for (int i=0; i < N; i++)
		sch[i] =0;
	while (count--) {
		scanf("%d %d", &n, &m);
		sch[n-1] += m;
	}
	int max=0;
	for (int i=0; i < N; i++)
		if (sch[i] > sch[max])
			max = i;

	printf("%d %d\n", max+1, sch[max]);

	return 0;
}
