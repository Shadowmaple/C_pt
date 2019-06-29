# include <stdio.h>
# include <string.h>

int main()
{
	int n;
	int id[n], grade[n];
	int k = 0;

	for (int i=0; i < n; i++) {
		grade[i] = 0;	
		id[i] = 0;
	}
	for (int i=0; i < n; i++) {
		int id_buffer, grade_buffer, buffer;
		scanf("%d-%d %d", &id_buffer, &buffer, &grade_buffer);
		for (int j=0; j < k; j++) {
			if (id[k] == id_buffer) {
				grade[k] += grade_buffer;
				break;
			} else if (!id[k]) {
				id[++k] = id_buffer;
				grade[k] = grade_buffer;
				break;
			}
		}
	}
	int max_id, max = 0;
	for (int i=0; i < k; i++)
		if (grade[i] > max) {
			max = grade[i];
			max_id = id[i];
		}

	printf("%d %d\n", max_id, max);

	return 0;
}
