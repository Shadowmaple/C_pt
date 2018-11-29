#include <stdio.h>
#include <math.h>

int ser(int b)
{
	int check=0;
	while (!check) {
		b += 2;
		int ch = 1;
		for (int i=2; i<=sqrt(b);) {
			if (b%i==0) {
				ch = 0;
				break;
			}
			if (i>2) i+=2;
			else i++;
		}
		if (ch)
			check=1;
	}
	return b;

}

int main()
{
	int n;
	scanf("%d", &n);
	int a=3, b=5, sum=0;
	int m = 2, count=0;
	while (b<=n) {
		if (b-a==2)
			count++;
		a = b;
		b = ser(b);
	}
	printf("%d\n", count);
	return 0;
}
