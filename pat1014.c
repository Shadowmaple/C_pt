#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
	char str[4][61];
	for (int i=0; i<4; i++) {
		scanf("%s", str[i]);
	}
	char day[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char a[2];
	int count=0;
	for (int i=0; i<strlen(str[0]); i++) {
		char c = str[0][i];
		if (!count) {
			if (isupper(c) && c==str[1][i]) {
				a[count++] = c;
			}
		} else {
			if ((isupper(c) || isdigit(c)) && c==str[1][i]) {
				a[count] = c;
				break;
			}
		}
	}

	int index;
	for (int i=0; i<strlen(str[2]); i++) {
		char c = str[2][i];
		if (isalpha(c) && c==str[3][i]) {
			index = i;
			break;
		}
	}
	
	int week = a[0]-'A'+1;
	int hour;
	if (isdigit(a[1]))
		hour = a[1]-'0'+1;
	else
		hour = a[1]-'A'+10;

	printf("%s %02d:%02d\n", day[week-1], hour, index);

	return 0;
}
