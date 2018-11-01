#include <stdio.h>

int main()
{
	int Q, N;
	while (1) {
		scanf("%d%d", &Q, &N);
		getchar();

		if (N == 0) break;
		double price[N][50], sum[N];
		int n[N];
		//发票的物品数
		char type[N][50];

		//输入并计算总额
		for (int i=0; i < N; i++)  {
			sum[i] = 0;
			scanf("%d", &n[i]);
			for (int j=0; j < n[i]; j++) {
				scanf("%c%lf", &type[i][j], &price[i][j]);
				sum[i] += price[i][j];
			}
		}

		int mean[N];//是否可以报销

		for (int i =0; i < N; i++) {
			int count =0;
			mean[i] = 1;
			if (sum[i] > Q) {
				mean[i] = 0;
				continue;
			}
			while (type[count]) {
				if (type[i][count]!='A' && type[i][count]!='B' && type[i][count]!='C')
				{
					mean[i] = 0;
					break;
				}
				count++;
			}
			double max = 0;
			for (int j=0; j < N; j++) {
				if (!mean[j]) continue;
				max = (max > sum[j]) ? max:sum[j];
			}
			printf("%.2f\n", max);
		}
	}
}
