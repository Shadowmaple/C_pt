#include <stdio.h>

int main ()
{
	int N;
	scanf("%d", &N);
	int n[N], sum[N];
	for (int i=0; i < N; i++) {
		scanf("%d", &n[i]);
		sum[i] =0;
		while (n[i]) {
			sum[i] += n[i] % 10;
			n[i] /= 10;
		}
	}
	int num[N], count =0;
	for (int i=0; i < N; i++){
		for (int j=i; j < N; j++) {
			if (sum[i] == sum[j]) {
				int check=1;
				for (int k=0; k < count; k++)
					if (num[k] == sum[i]) {
						check=0;
						break;
					}
				if (check)
					num[count++] = sum[j];
			}
		}
	}
	for (int i=0; i < count; i++){
		int k=i;
		for (int j=i+1; j < count; j++) {
			if (num[j] < num[k])
				k = j;
		}
		if (k != i) {
			int w = num[k];
			num[k] = num[i];
			num[i] = w;
		}
	}
	printf("%d\n", count);
	for (int i=0; i < count; i++) {
		printf("%d", num[i]);
		if (i != count-1) putchar(' ');
		else putchar('\n');
	}
	return 0;
}
