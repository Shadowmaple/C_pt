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
	int i=0;
	for (;i<strlen(str[0]); i++) {
		char c = str[0][i];
		if (c>='A' && c<='G' && c==str[1][i]) {
			int week = c-'A'+1;
			printf("%s ", day[week-1]);
			break;
		}
	}

	for (i=i+1; i<strlen(str[0]); i++) {
		char c = str[0][i];
		if (c==str[1][i]) {
			if (isdigit(c))
				printf("%02d:", c-'0'+1);
			else if (c>='A' && c<='N')
				printf("%02d:", c-'A'+10);
			break;
		}
	}

//	int index;
	for (int i=0; i<strlen(str[2]); i++) {
		char c = str[2][i];
		if (isalpha(c) && c==str[3][i]) {
//			index = i;
			printf("%02d\n", i);			
			break;
		}
	}
	
//	printf("%s %02d:%02d\n", day[week-1], hour, index);

	return 0;
}

