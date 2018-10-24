#include <stdio.h>

int sh(char x[])
{
	int i=0;
	while (x[i++]) ;
	return i-1;
}

int main()
{
	char a[100], b[100];
	int n, n1=0, n2=0;

	scanf("%s", a);
	scanf("%s", b);
	
	n1 = sh(a);
	n2 = sh(b);

	for (int i=0; i < n1; i++) {
		int j=0;
		int k = i;
		while (a[k] == b[j] && b[j] != '\0') {
			k++; j++;
		}
		
		if (j == n2) {
			n = i+1;
			break;
		}
	}

	printf("%d\n", n);

	return 0;
}
