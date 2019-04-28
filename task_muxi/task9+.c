#include <stdio.h>

int check(int y, int m, int d)
{
	int ck = 0;
	if (m >12 || m<1 || d <1 || d > 31 || y < 0) {
		ck = 1;
		puts("error!");
	} else
		switch (m) {
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: if (d > 31) {
					 puts("error!");
					 ck =  1;
				 }
				break;
		case 4:
		case 6:
		case 9:
		case 11: if (d > 30) {
					 puts("error!");
					 ck = 1;
				 }
				break;
		default :if (y %400==0 || (y %100!=0 && y %4==0)) {
					 if (d > 29) {
						puts("error!");
						ck = 1;
					 }
				 } else {
					if (d > 28) {
						puts("error!");
						ck = 1;
					}
				 }
	}
	return ck;	
}

int main()
{
	int year[100], month[100], day[100], sum[100]={0};
	int line = 0, a[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	while (3 == scanf("%d/%d/%d", &year[line], &month[line], &day[line]))
	{
		if (check(year[line], month[line], day[line]))
			continue;
		else {
			for (int i=0; i < month[line]-1; i++)
				sum[line] += a[i];

			sum[line] +=day[line];
			if (year[line] %400==0 || (year[line] %100!=0 && year[line] %4==0))
				sum[line]++;
		}
		line++;
	}

	for (int i=0; i <line; i++)
		printf("%d\n", sum[i]);

	return 0;
}
