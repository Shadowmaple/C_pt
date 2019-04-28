#include <stdio.h>
#include <string.h>

int main()
{
	char s[81];
	scanf("%[^\n]", s);
	char word[80][10];
	int n=0, m[80];
	int k=0, length =strlen(s);
	for (int i=0; i < length; i++) {
		int d;
		if (s[i]==' ' || i==length-1) {
			if (i==length-1)
				d = i+1;
			else d =i;
			m[n] = 0;
			for (int j=k, p=0; j < d; p++,j++) {
				word[n][p] = s[j];
				m[n]++;
			}
			n++;
			k = i+1;
		}
	}
	for (int i=n-1; i >= 0; i--) {
		for (int j=0; j < m[i]; j++)
			printf("%c", word[i][j]);
		if (i!=0) putchar(' ');
		else putchar('\n');
	}
	return 0;
}
