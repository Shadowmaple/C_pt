#include <stdio.h>
#include <stdlib.h>
long a[1002][1002] = {0};
int unique(int m, int n, int M, int N)
{
	for (int i=0; i < M; i++)
		for (int j=0; j < N; j++){
			if (m==i && n==j) continue;
			if (a[m+1][n+1]==a[i+1][j+1])
				return 0;
		}
	return 1;
}

int main()
{
	int M, N, TOL;
	scanf("%d %d %d", &M, &N, &TOL);
	for (int i=0; i < N; i++)
		for (int j=0; j < M; j++) {
			scanf("%ld", &a[i+1][j+1]);
		}
	int x, y, exist=0;
	for (int i=0; i < N; i++) {
		int br =0;
		for (int j=0; j < M; j++) {
			if (!unique(i,j,M,N)) continue;
			int check=0;
			for (int m=i-1; m <=i+1; m++) {
				for (int n=j-1; n <=j+1; n++) {
					if (m==i && n==j) continue;
					if (abs(a[i+1][j+1]-a[m+1][n+1]) > TOL) {
						check++;
					}
				}
			}
			if (check == 8) {
				if (!exist) {
					exist =1;
					x = j;
					y = i;
				} else {
					exist = -1;
					br = 1;
					break;
				}
			}
		}
		if (br) break;
	}
	if (!exist)
		puts("Not Exist");
	else if (exist==-1)
		puts("Not Unique");
	else
		printf("(%d, %d): %ld\n", x+1, y+1, a[y+1][x+1]);
	return 0;
}
