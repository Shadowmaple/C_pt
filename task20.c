#include <stdio.h>
#include <math.h>

double add(int a)
{
	double plus=0;
	for (int n=1; n <= a; n++) {
		plus += pow(-1, n-1)*(double)1/n;
	}
	return plus;

}

int main()
{
	int m;
	scanf("%d", &m);

	int n[m];
	double sum[m];

	for (int i=0; i < m; i++) {
		scanf("%d", &n[i]);
		sum[i] = add(n[i]);
	}
	for (int i=0; i < m; i++)
		printf("%.2f\n", sum[i]);


	return 0;
}
