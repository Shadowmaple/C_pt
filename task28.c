#include <stdio.h>
#include <string.h>

int main()
{
	int n;
	scanf("%d", &n);

	while (n-- > 0) {
		char str[100];
		scanf("%s", str);
		int sum=0;
		for (int i=0; i < strlen(str); i++) {
			if (str[i] >= '0' && str[i] <= '9')
				sum++;
		}
		printf("%d\n", sum);
	}

	return 0;
}
