#include <stdio.h>

int main()
{
	int n=0, a[15];

	do {
		scanf("%d", &a[n]);
		if (a[n])
			n++;
		else
			break;
	
	
	
	} while (1);
	int sum=0;

	for (int i=0; i < n; i++) {
		for (int j =0; j < n; j++) {
			if (a[i]*2 == a[j] || a[i] == a[j]*2)
				sum++;
		}
	}

	printf("%d\n", sum/2);

	return 0;
}
