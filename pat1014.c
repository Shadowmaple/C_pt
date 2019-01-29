#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
/*
	char str[4][61];
	for (int i=0; i<4; i++) {
		scanf("%s", str[i]);
	}
*/
	char str1[61], str2[61], str3[61], str4[61];
    scanf("%s %s %s %s", str1, str2, str3, str4);

	char day[7][4] = {"MON","TUE","WED","THU","FRI","SAT","SUN"};
	char a[2];
	int i=0;
	for (; i<strlen(str1); i++) {
		char c = str1[i];
		if (c>='A' && c<='G' && c==str2[i]) {
			int week = c-'A'+1;
			printf("%s ", day[week-1]);
			break;
		}
	}

	for (i=i+1; i<strlen(str1); i++) {
		char c = str1[i];
		if (c==str2[i]) {
			if (isdigit(c))
				printf("%02d:", c-'0'+1);
			else if (c>='A' && c<='N')
				printf("%02d:", c-'A'+10);
			break;
		}
	}

//	int index;
	for (int i=0; i<strlen(str3); i++) {
		char c = str3[i];
		if (isalpha(c) && c==str4[i]) {
//			index = i;
			printf("%02d\n", i);			
			break;
		}
	}
	
//	printf("%s %02d:%02d\n", day[week-1], hour, index);

	return 0;
}

