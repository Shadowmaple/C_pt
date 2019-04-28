#include <stdio.h>
#include <string.h>

void sort_(char (*id)[9], int m[], int t[], int total)
{
	for (int i=0; i<total-1; i++) {
		int sum = m[i] + t[i];
		int k = i;
		for (int j=i+1; j<total; j++) {
			if (sum < m[j]+t[j])
				k = j;
			else if (sum == m[j]+t[j]) {
				if (m[i] < m[j])
					k = j;
				else if (id[i] > id[j])
					k = j;
			}
		}
		if (k != i) {
			int x = m[i]; m[i] = m[k]; m[k] = x;
			x = t[i]; t[i] = t[k]; t[k] = x;
			char c[9];
			strcpy(c, id[i]);
			strcpy(id[i],id[k]);
			strcpy(id[k], c);
		}
	}
}

int main()
{
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	char id_1[n][9], id_2[n][9], id_3[n][9], id_4[n][9];
	char id_x[9];
	int morality[4][n], talent[4][n];
	int morality_x, talent_x;
	int level[4] = {0};
	//各类考生总数

	for (int i=0; i<n; i++) {
		scanf("%s %d %d", id_x, &morality_x, &talent_x);
		if (morality_x<l || talent_x<l)
			continue;
		if (morality_x>=h && talent_x>=h) {		//德才全尽
			int num = level[0]++;
			strcpy(id_1[num], id_x);
			morality[0][num] = morality_x;
			talent[0][num] = talent_x;
		}
		else if (morality_x>=h) {				//德胜才
			int num = level[1]++;
			strcpy(id_2[num], id_x);
			morality[1][num] = morality_x;
			talent[1][num] = talent_x;
		}
		else if (morality_x>=talent_x) {		//才德兼亡但德胜才
			int num = level[2]++;
			strcpy(id_3[num], id_x);
			morality[2][num] = morality_x;
			talent[2][num] = talent_x;
		}
		else {									//其他达线者
			int num = level[3]++;
			strcpy(id_4[num], id_x);
			morality[3][num] = morality_x;
			talent[3][num] = talent_x;
		}
	}

	sort_(&id_1[level[0]], morality[0], talent[0], level[0]);
	sort_(&id_2[level[1]], morality[1], talent[1], level[1]);
	sort_(&id_3[level[2]], morality[2], talent[2], level[2]);
	sort_(&id_4[level[3]], morality[3], talent[3], level[3]);

	printf("%d\n", level[0]+level[1]+level[2]+level[3]);
	for (int i=0; i<level[0]; i++)
		printf("%s %d %d\n", id_1[i], morality[0][i], talent[0][i]);
	for (int i=0; i<level[1]; i++)
		printf("%s %d %d\n", id_2[i], morality[1][i], talent[1][i]);
	for (int i=0; i<level[2]; i++)
		printf("%s %d %d\n", id_3[i], morality[2][i], talent[2][i]);
	for (int i=0; i<level[3]; i++)
		printf("%s %d %d\n", id_4[i], morality[3][i], talent[3][i]);


	return 0;
}
