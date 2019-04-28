#include <stdio.h>

int main ()
{
	int N;
	scanf("%d", &N);
	int n[N];
	for (int i=0; i < N; i++) {
		scanf("%d", &n[i]);
		if (!n[i])
			i--;
	}

	int count=0;
	int sum=0;
	int num[36288]={0};

	for (int i=0; i < N; i++) {
		for (int j=0; j < N; j++) {

			if (i == j)
				continue;
			int check=1;
			for (int k=0; k < count; k++) {
				if (num[k] == n[i]*10+n[j]) {
					check=0;
					break;
				}
			}

			if (check)
				num[count++] = n[i]*10+n[j];
		}
	
	}

	for (int i=0; i < count; i++)
		sum += num[i];

	printf("%d\n", sum);
	
	return 0;
}
