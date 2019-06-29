# include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);

	int id[n], grade[n];
	int k = 0;
	
	for (int i=0; i < n; i++) {
		grade[i] = 0;	
		id[i] = 0;
	}
	for (int i=0; i < n; i++) {
		int id_buffer, grade_buffer, buffer;
		scanf("%d-%d %d", &id_buffer, &buffer, &grade_buffer);
		int j;
		for (j=0; j < k; j++) {
			if (id[j] == id_buffer) {
				grade[j] += grade_buffer;
				break;
			}
		}
		if (j >= k) {
			id[k] = id_buffer;
			grade[k] = grade_buffer;
			k++;
		}
	}
	int max_id = 0, max = 0;
	for (int i=0; i < k; i++)
		if (grade[i] > max) {
			max = grade[i];
			max_id = id[i];
		}

	printf("%d %d\n", max_id, max);
	return 0;
}
