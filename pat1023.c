#include <stdio.h>

int main()
{
	int n[10];
	for(int i=0; i < 10; i++)
		scanf("%d", &n[i]);
	int count=0;
	if (n[0])
		for (int i=1; i < 10; i++)
			if (n[i]) {
				printf("%d", i);
				count++;
				n[i]--;
				break;
			}

	for (int i=0; i < 10; i++)
		while (n[i]--)
			printf("%d", i);

	putchar('\n');
	return 0;
}
