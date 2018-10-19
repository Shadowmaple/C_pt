#include <stdio.h>

int rn(int run)
{
	if (run == 'F') return 28;
	else return 29;
}

int xy(int run, int b, int c)
{
	int r;

	switch (b) {
		case 1: r = c; break;
		case 2: r = 31+c; break;
		case 3: r = 31+ rn(run) +c; break;
		case 4: r = 31*2+ rn(run) +c; break;
		case 5: r = 31*2+30+ rn(run) +c; break;
		case 6: r = 31*3+30+ rn(run) +c; break;
		case 7: r = 31*3+30*2+ rn(run) +c; break;
		case 8: r = 31*4+30*2+ rn(run) +c; break;
		case 9: r = 31*5+30*2+ rn(run) +c; break;
		case 10:r = 31*5+30*3+ rn(run) +c; break;
		case 11:r = 31*6+30*3+ rn(run) +c; break;
		case 12:r = 31*6+30*4+ rn(run) +c; break;
	}

	return r;
}

void num(int a[], int b[], int c[], int re[], int s)
{

	for (int i=0; i < s; i++) {
		int run = 'T';

		if (a[i] % 100) {
			if (a[i] % 4) {
				run = 'F';
				re[i] = xy(run, b[i], c[i]);
			}
			else re[i] = xy(run, b[i], c[i]);

		} else {
			if (!(a[i] % 400)) {
				run = 'F';
				re[i] = xy(run, b[i], c[i]);
			}
			else re[i] = xy(run, b[i], c[i]);
		}

	}


}

int main()
{
	int year[100], month[100], day[100];
	int re[100], line =0;

	do {
		scanf("%d/%d/%d", &year[line], &month[line], &day[line]);
		if (month[line] > 12 || month[line] < 1 || day[line] > 31 ||
			day[line] < 1 || year[line] < 0)
			puts("error!");

		line++;

	} while (year[line] != 0);

	num(year, month, day, re, line);

	for (int i=0; i < line; i++)
		printf("%d\n", re[i]);

	return 0;
}
