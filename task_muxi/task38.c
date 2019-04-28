#include <stdio.h>

int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int mark[M], answer[M];
	for (int i=0; i < M; i++)
		scanf("%d", &mark[i]);
	for (int i=0; i < M; i++)
		scanf("%d", &answer[i]);
	int grade[N][M], sum[N];
	for (int i=0; i < N; i++) {
		sum[i] =0;
		for (int j=0; j < M; j++) {
			scanf("%d", &grade[i][j]);
			if (grade[i][j] == answer[j])
				sum[i] += mark[j];
		}	
	}

	for (int k=0; k < N; k++)
		printf("%d\n", sum[k]);

	return 0;
}
