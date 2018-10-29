#include <stdio.h>
#include <string.h>

int main()
{
	int n;

	scanf("%d", &n);

	int result[n][5];
	char s[n][100];


	for (int num=0; num < n; num++) {
		getchar();
		scanf("%[^\n]", s[num]);
		for (int i=0; i < 5; i++)
			result[num][i] = 0;

		for (int i=0; i < strlen(s[num]); i ++){
			switch (s[num][i]) {
				case 'a': result[num][0]++;break;
				case 'e': result[num][1]++;break;
				case 'i': result[num][2]++;break;
				case 'o': result[num][3]++;break;
				case 'u': result[num][4]++;break;
			}
		
		}
	}

	for (int i=0; i < n; i++) {
		printf("a:%d\n", result[i][0]);
		printf("e:%d\n", result[i][1]);
		printf("i:%d\n", result[i][2]);
		printf("o:%d\n", result[i][3]);
		printf("u:%d\n", result[i][4]);
		if (i != n-1) putchar('\v');
	}
	return 0;
}
