#include <stdio.h>
#include <string.h>

int main()
{
	char st[1001], character[26];
	int sum[26], count=0;
	scanf("%[^\n]", st);
	for (int i=0; i < strlen(st); i++) {
		if (st[i] >= 'A' && st[i] <= 'Z')
			st[i] =st[i] + 32;

		if (st[i] > 'z' || st[i] < 'a')
			continue;

		int check =1, step;
		for (int j=0; j < count; j++) {
			if (character[j] == st[i]) {
				check =0;
				step =j;
				break;
			}
		}
		if (check) {
			character[count] =st[i];
			sum[count++] =1;
		}
		else
			sum[step]++;
	}
	
	int max=0;
	for (int i=0; i < count; i++) {
		if (sum[i] > sum[max]) {
			max = i;
		}
		else if (sum[i] == sum[max]) {
			if (character[i] < character[max])
				max = i;
		}
	}

	printf("%c %d\n", character[max], sum[max]);
	return 0;
}
