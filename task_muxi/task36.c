#include <stdio.h>

int main()
{
	long n;
	scanf("%ld", &n);
	char name[n][6];
	int year[n], month[n], day[n];
	int check[n], count=0;
	long sum[n];
	for (int i=0; i < n; i++) {
		check[i] = 1;
		scanf("%s %d/%d/%d", name[i], &year[i], &month[i], &day[i]);
		sum[i] = year[i]*10000 + month[i]*100 + day[i];

		if (sum[i] > 20140906 || sum[i] < 18140906)
			check[i] =0;
		else
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

		if (sum[i] < sum[max])
			max =i;
		if (sum[i] > sum[min])
			min =i;
	}

	if (!count)
		printf("0\n");
	else
		printf("%d %s %s\n", count, name[max], name[min]);
	return 0;
}
