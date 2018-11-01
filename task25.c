#include <stdio.h>
#include <math.h>

int main()
{
	double r1, r2, p1, p2;
	scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);
	double r = r1 * r2, p = p1 + p2;
	double a = r * cos(p), b = r * sin(p);

	if (-0.05< a && a < 0)
		printf("0.00");
	else
		printf("%.2f", a);
	if (-0.05< b && b < 0)
		printf("+0.00i\n");
	else if (b >= 0)
		printf("+%.2fi\n", b);
	else
		printf("%.2fi\n", b);

	return 0;
}
