#include <stdio.h>

int main()
{
	int N, Z;
	scanf("%d", &N);
	char id[N][19];
	char M[11] = {'1','0','X','9','8','7','6','5','4','3','2'};
	int a[17] ={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int check[N], all=1;
	for (int i=0; i < N; i++) {
		scanf("%s", id[i]);
		check[i] =1;
		int sum =0;

		for (int j=0; j <17; j++) {
			if (id[i][j] <'0' || id[i][j] >'9') {
				check[i] =0;
				break;
			}
			sum += a[j]*(id[i][j]-'0');
		}

		if (!check[i]) {
			all =0;
			continue;
		}
		else {
			Z = sum % 11;
			if (M[Z] != id[i][17]) {
				check[i] =0;
				all =0;
			}
		}
	}
	if (all)
		puts("All passed");
	else
		for (int i=0; i < N; i++)
			if (!check[i])
				printf("%s\n", id[i]);

	return 0;
}
