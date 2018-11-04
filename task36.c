#include <stdio.h>

int main()
{
	long n;
	scanf("%ld", &n);
	char name[n][5];
	int year[n], month[n], day[n];
	int check[n], count=0;
	for (int i=0; i < n; i++) {
		check[i] = 1;
		scanf("%s %d/%d/%d", name[i], &year, &month, &day);
		if (year > 2014 || year < 1814)
			check[i] =0;
		else if (year == 2014) {
			if (month > 9)
				check[i] =0;
			else if (month = 9)
				if (day > 6) check[i] =0;
		}
		else if (year == 1814) {
			if (month < 9)
				check[i] = 0;
			else if (month == 9)
				if (day < 6) check[i] =0;
		}
		if (check[i])
			count++;
	}

	for (int i=0; i < n; i++)
		if (check[i]) {
			int max=i, min=i;
			break;
		}

	for (int i=1; i < n; i++) {
		if (!check[i])
			continue;

		if (year[i] < year[max])
			max = i;
		else if (year[i] == year[max]) {
			if (month[i] < month[max])
				max = i;
			else if (month[i] == month[max])
				if (day[i] < day[max])
					max = i;
		}

		if (year[i] > year[min])
			min = i;
		else if (year[i] == year[min]) {
			if (month[i] > month[min])
				min = i;
			else if (month[i] == month[min])
				if (day[i] > day[min])
					min = i;
		}

	}

	printf("%d %s %s\n", count-1, name[max], name[min]);
	return 0;
}
