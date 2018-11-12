#include <stdio.h>

int main()
{
	int n[10];
	for(int i=0; i < 10; i++)
		scanf("%d", &n[i]);
	char num[51];
	int count=0;
	if (n[0])
		for (int i=1; i < 10; i++)
			if (n[i]--) {
				num[0] = i+'0';
				count++;
				break;
			}
	for (int i=0; i < 10; i++)
		while (n[i]--)
			num[count++] = i+'0';

	for (int i=0; i < count; i++)
		printf("%c", num[i]);
	putchar('\n');
	return 0;
}
