#include <stdio.h>

int main()
{
	int year[100][100], month[100][100], day[100][100];
	
	scanf("%d/%d/%d", &year, &month, &day);
	if (month > 12 || month < 1 || day > 31 ||
			day < 1 || year < 1) puts("error!");
	else {
		if (year % 4)



	}

	return 0;
}
