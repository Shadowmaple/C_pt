#include <stdio.h>

void check(int x)
{
	if (x)
		printf("%d", x);
	else
		printf("N");
}

int main()
{
	int n;
	scanf("%d", &n);
	int num[n];
	int a1=0, a2=0, a3=0, a5=0;
	int a4_num=0, a2_n=1, a2_num=0;
	double a4=0;
	for (int i=0; i<n; i++) {
		scanf("%d", &num[i]);
		switch (num[i] % 5) {
			case 0:
				if (num[i] % 2==0)
					a1 += num[i];
				break;
			case 2: a3++; break;
			case 3: a4 += num[i]; a4_num++; break;
			case 4: a5 = (a5 > num[i]) ? a5:num[i]; break;
			default: a2 += a2_n * num[i];
					 a2_n *= -1;
					 a2_num++;
		}
	}
	a4 /= a4_num;
	check(a1);
	putchar(' ');
	if (a2_num)
		printf("%d ", a2);
	else
		printf("N ");
	check(a3);
	putchar(' ');
	if (a4_num)
		printf("%.1lf ", a4);
	else
		printf("N ");
	check(a5);
	putchar('\n');

	return 0;
}
