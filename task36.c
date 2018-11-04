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
		scanf("%s %d/%d/%d", name[i], &year[i], &month[i], &day[i]);
		if (year[i] > 2014 || year[i] < 1814)
			check[i] =0;
		else if (year[i] == 2014) {
			if (month[i] > 9)
				check[i] =0;
			else if (month[i] = 9)
				if (day[i] > 6) check[i] =0;
		}
		else if (year[i] == 1814) {
			if (month[i] < 9)
				check[i] = 0;
			else if (month[i] == 9)
				if (day[i] < 6) check[i] =0;
		}
		if (check[i])
			count++;
	}

	int max, min;
	for (int i=0; i < n; i++)
		if (check[i]) {
			max=min=i;
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

	printf("%d %s %s\n", count, name[max], name[min]);
	return 0;
}
