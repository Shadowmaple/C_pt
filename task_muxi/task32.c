#include <stdio.h>
#include <string.h>

int main()
{
	char n[3];
	while(scanf("%s", n) != EOF) {
		int count =strlen(n);
		for (int i=0; i < strlen(n); i++) {
			for (int j=0; j < n[i]-'0'; j++) {
				if (count == 3)
					putchar('B');
				else if (count == 2)
					putchar('S');
				else
					printf("%d", j+1);
			}
			count--;
		}
		putchar('\n');
	}
}
