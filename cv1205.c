#include <stdio.h>
#include <string.h>

int main()
{
	char a[100], b[100][100];
	int n;

	scanf("%[^\n]", a);
	n = strlen(a);

	int n1=0, n2, k=0;
	for (int i=0; i <= n; i++) {
		if (a[i] == ' ' || a[i] == '\0') {
			n2 = i-1;
			for (int j =n1, h=0; j <= n2; h++,j++) {
				b[k][h] = a[j];
			}
			k++;
			n1 = i +1;
		}
	}
	
	for (int i= k-1; i >= 0; i--)
		printf("%s ", b[i]);

	putchar('\n');
	return 0;
}
