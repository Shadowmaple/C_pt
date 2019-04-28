#include <stdio.h>

int main()
{
	float n;
	char c;
	scanf("%f %c", &n, &c);
	int line =(n/2) + 0.5;
	for (int i=0; i < line; i++) {
		for (int j=0; j < n; j++) {
			if (i == 0 || i == line-1)
				putchar(c);
			else {
				if (j == 0 || j == n-1)
					putchar(c);
				else
					putchar(' ');
			}
		}
		putchar('\n');
	}
	return 0;
}
