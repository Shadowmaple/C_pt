#include <stdio.h>
#include <math.h>

int main()
{
	int N;
	scanf("%d", &N);
	double a[N], b[N], r[N];
	for (int i=0; i < N; i++) {
		scanf("%lf %lf", &a[i], &b[i]);
		r[i] = sqrt(a[i]*a[i] + b[i]*b[i]);
	}
	double max=0;
	for (int i=0; i < N; i++)
		max = (max > r[i])? max:r[i];
	printf("%.2f\n", max);


	return 0;
}
