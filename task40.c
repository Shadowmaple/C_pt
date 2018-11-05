#include <stdio.h>

int main()
{
	int T, K;
	scanf("%d%d", &T, &K);
	int n1[K], b[K], n2[K], t[K], x;
	x = T;
	for (int i=0; i < K; i++) {
		scanf("%d%d%d%d", &n1[i], &b[i], &t[i], &n2[i]);
	}

	for (int i=0; i < K; i++) {
		if (t[i] > x) {
			printf("Not enough tokens.  Total = %d.\n", x);
			continue;
		}

		if (n2[i] > n1[i]) {
			if (b[i]) {
				x +=t[i];
				printf("Win %d!  Total = %d.\n", t[i], x);
			}
			else{
				x -=t[i];
				printf("Lost %d.  Total = %d.\n", t[i], x);
			}
		}
		else {
			if (b[i]) {
				x -=t[i];
				printf("Lost %d.  Total = %d.\n", t[i], x);
			}
			else {
				x +=t[i];
				printf("Win %d!  Total = %d.\n", t[i], x);
			}
		}
		if (!x){
			puts("Game Over.");
			break;
		}
	}
	return 0;
}
