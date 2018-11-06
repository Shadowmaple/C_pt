#include <stdio.h>

int main()
{
	int T, K;
	scanf("%d%d", &T, &K);
	int n1, b, n2, t, x;
	x = T;
	for (int i=0; i < K; i++) {
		scanf("%d%d%d%d", &n1, &b, &t, &n2);

		if (t > x) {
			printf("Not enough tokens.  Total = %d.\n", x);
			continue;
		}

		if (n2 > n1) {
			if (b) {
				x +=t;
				printf("Win %d!  Total = %d.\n", t, x);
			}
			else{
				x -=t;
				printf("Lose %d.  Total = %d.\n", t, x);
			}
		}
		else {
			if (b) {
				x -=t;
				printf("Lose %d.  Total = %d.\n", t, x);
			}
			else {
				x +=t;
				printf("Win %d!  Total = %d.\n", t, x);
			}
		}
		if (!x){
			puts("Game Over.");
			break;
		}
	}
	return 0;
}
