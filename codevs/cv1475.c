#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
	int m, sum=0;
	char n[7];
	scanf("%s%d", n, &m);
	int len = strlen(n);
	int count =0;
	for (int i=0; i<len; i++)
		if (n[i]>='0' && n[i]<='9')
			sum += (n[i]-'0')*pow(m, len-i-1);
		else
			sum += (n[i]-'A'+10)*pow(m, len-i-1);

	printf("%d\n", sum);

	return 0;
}
