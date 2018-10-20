#include <stdio.h>

int rs();

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
		re[i] = xy(rs(a[i]), b[i], c[i]);
	}
}

int rs(int run)
{
	//判断是否为闰年
	if (run % 100) {
		if (run % 4)
			return 'F';
		else return 'T';

	} else {
		if (run % 400)
			return 'F';
		else return 'T';
	}
}

//查验错误
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
		default :if (rs(y) == 'T') {
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
	//line为行数即有几组，re[]为最后的第几天
	int year[100], month[100], day[100];
	int re[100], line =-1;
	
	//输入，输入0则停止
	do {
		line++;
		scanf("%d/%d/%d", &year[line], &month[line], &day[line]);

		if (!year[line]) break;
		else if (check(year[line], month[line], day[line]))
				line--;

	} while (1);

	num(year, month, day, re, line);
	
	//输出
	for (int i=0; i < line; i++)
		printf("%d\n", re[i]);

	return 0;
}
