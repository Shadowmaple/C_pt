# include <stdio.h>
# define S(n)  (2 * (n*n + 2*n) + 1)

int main()
{
	int sum;
	char c;
	scanf("%d %c", &sum, &c);
	int num = 0;
	int n;
	for (int i=1; i <= sum; i++) {
		int s = S(i);
		if (s <= sum)
			continue;
		n = i - 1;
		num = sum - S(n);
		break;
	}

	for (int i=1; i <= n; i++) {
		for (int j=0; j < i-1; j++)
			putchar(' ');
		for (int j=0; j < (n-i+1)*2+1; j++) {
			printf("%c", c);
		}
		putchar('\n');
	}
	for (int i=0; i < n; i++)
		putchar(' ');
	printf("%c\n", c);
	for (int i=0; i < n; i++) {
		for (int j=0; j < n-i-1; j++)
			putchar(' ');
		for (int j=0; j < 2*(i+1)+1; j++) {
			printf("%c", c);
		}
		putchar('\n');
	}
	printf("%d\n", num);
   
    return 0;
}
