# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

int isPrime(int num)
{
    int flag = 1;
    for (int i = 2; i < sqrt(num); i++)
        if (num % i == 0) {
            flag = 0;
            break;
        }
    // 是素数
    if (flag) return 1;
    else return 0;
}

int main()
{
    int N, K;
    scanf("%d", &N);
    char id[N][5];
    int flag[N];
    for (int i=0; i < N; i++) {
        flag[i] = 0;
        scanf("%s", id[i]);
    }

    scanf("%d", &K);

    char check[K][5];
    for (int i=0; i < K; i++) {
        scanf("%s", check[i]);
        // search(id, flag, check[i], N);
        int f = 1;
		for (int j=0; j < N; j++) {
			if (!strcmp(id[j], check[i])) {
				if (flag[j]) printf("%s: Checked\n", check[i]);
				else if (!j) {
					printf("%s: Mystery Award\n", check[i]);
					flag[j] = 1;
				} else if (isPrime(j + 1)) {
					printf("%s: Minion\n", check[i]);
					flag[j] = 1;
				} else {
					printf("%s: Chocolate\n", check[i]);
					flag[j] = 1;
				}
				f = 0;
				break;
			}
		}
		if (f) printf("%s: Are you kidding?\n", check[i]);
    }

    return 0;
}
