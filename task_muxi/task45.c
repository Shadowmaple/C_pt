#include <stdio.h>
#include <string.h>

int main()
{
	char str[101];
	while (1) {
		scanf("%s", str);
		if (str[0] == 'E') break;
		int z=0, o=0, j=0;
		for (int i=0; i < strlen(str); i++) {
			if (str[i] == 'Z') z++;
			else if (str[i] == 'O') o++;
			else if (str[i] == 'J') j++;
		}
		while (z !=0 || o!=0 || j!=0) {
			if (z > 0) {
				putchar('Z');
				z--;
			}
			if (o > 0) {	
				putchar('O');
				o--;
			}
			if (j > 0) {
				putchar('J');
				j--;
			}
		}
		putchar('\n');
	}

	return 0;
}
