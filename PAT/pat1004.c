#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	char name[n][11], id[n][11];
	int grade[n], max=0, min=0;
	for (int i=0; i < n; i++){
		scanf("%s %s %d", name[i], id[i], &grade[i]);
		max = (grade[max] > grade[i])? max:i;
		min = (grade[min] < grade[i])? min:i;
	}
	printf("%s %s\n", name[max], id[max]);
	printf("%s %s\n", name[min], id[min]);
	return 0;
}
