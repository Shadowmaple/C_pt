#include <stdio.h>

//返回2月份的天数
int rn(int run)
{
	if (run == 'F') return 28;
	else return 29;
}

//xy函数计算并返回天数
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
		//run为T则为闰年
		
		//判断是否为闰年
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
	//line为行数即有几组，re[]为最后的第几天
	int year[100], month[100], day[100];
	int re[100], line =0;
	
	//输入，输入0则停止
	do {
		scanf("%d/%d/%d", &year[line], &month[line], &day[line]);
		if (month[line] > 12 || month[line] < 1 || day[line] > 31 ||
			day[line] < 1 || year[line] < 0)
			puts("error!");

		line++;

	} while (year[line] != 0);

	num(year, month, day, re, line);
	
	//输出
	for (int i=0; i < line; i++)
		printf("%d\n", re[i]);

	return 0;
}
