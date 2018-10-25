#include <stdio.h>
#include <string.h>

/*int sh(char a[])
{
	int i=0;
	while (a[i++]) ;
	return i-1;

}
*/

int main()
{
	char a[100], b[100][100];
	int n;

	scanf("%[^\n]", a);
	n = strlen(a);
	puts(a);
	printf("%d\n", n);

	int n1=0, n2, k=0;
	for (int i=0; i < n; i++) {
		if (a[i] == ' ') {
			n2 = i-1;
			putchar('+');
			for (int j =n1, h=0; j <= n2; h++,j++) {
				b[k][h] = a[j];
				putchar(b[k][h]);
				putchar('*');
			
			}
			k++;
			n1 = i +1;	
		}
	
	
	
	}
	
	for (int i= k-1; i >= 0; i--) {
		puts(b[i]);
	}

	return 0;
}
