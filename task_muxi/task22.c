#include <stdio.h>
#define CLK_TCK 100

int main()
{
	long c1, c2;

	scanf("%ld%ld", &c1, &c2);
	double time1 =(double) (c2-c1) / CLK_TCK;
	int time = time1 + 0.5;
	int hh = 0, mm = 0, ss = 0;
	if (time >= 3600)
		hh = time / 3600;
	if (time >= 60)
		mm = (time % 3600) / 60;
	ss = time % 3600 % 60;

	printf("%02d:%02d:%02d\n", hh, mm, ss);

	return 0;
}
