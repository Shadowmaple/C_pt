#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	char n[100000];
	char chi[10][5] ={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
	scanf("%s", n);
	int sum =0;
	for (int i=0; i < strlen(n); i++) {
		sum += n[i] - '0';
	}

	int  num[10];
	int count = 0, no = sum;
	while (no){
		count++;
		no /= 10;
	}
	for (int i=count-1; i >=0; i--) {
		num[i] = sum % 10;
		sum /= 10;
	}

	for (int i=0; i < count; i++) {
		printf("%s", chi[num[i]]);
		if (i != count -1)
			putchar(' ');
	}
	putchar('\n');
	return 0;
}
