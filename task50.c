#include <stdio.h>
#include <stdlib.h>

int main()
{
	int M, N, TOL;
	scanf("%d %d %d", &M, &N, &TOL);
	long a[N][M];
	for (int i=0; i < N; i++) {
		for (int j =0; j < M; j++) {
			scanf("%ld", &a[i][j]);
		}
	}
	int x[1000], y[1000];
	int count =0;
	for (int i=0; i < N; i++) {
		for (int j=0; j < M; j++){
			
			int check=0;//是否是一点，为8时则符合
			int ck =0;//跳出循环
			for (int m=i-1; m <= i+1; m++) {
				for (int n=j-1; n <= j+1; n++) {
					if (m == i && n == j) continue;
					if (abs(a[i][j] - a[m][n]) > TOL)
						check++;
					else {
						ck = 1;
						break;
					}
				}
				if (ck) break;
			}
			if (i ==0 || i == N-1)
				if (j ==0 || j == M-1) check +=5;
				else check += 3;
			else if (j == 0 || j == M-1)
				check += 3;
			if (check == 8) {
//				printf("_%d %d %ld\n", j+1, i+1, a[i][j]);
				int out =0;
				for (int k=0; k < count; k++) {
					if (a[y[k]][x[k]] == a[i][j]) {
						for (int g=k; g < count-1; g++) {
							x[g] = x[g+1];
							y[g] = y[g+1];
						}
						count--;
						out =1;
						break;
					}
				}
				if (!out) {
					x[count] = j;
					y[count++] = i;
				}
			}
		}
	}
	if (!count)
		puts("Not Exist");
	else if (count == 1)
		printf("(%d, %d): %ld\n", x[0]+1, y[0]+1, a[y[0]][x[0]]);
	else
		puts("Not Unique");

	return 0;
}
