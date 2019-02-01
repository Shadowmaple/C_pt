#include <stdio.h>

int main()
{
	int n, l, h;
	scanf("%d %d %d", &n, &l, &h);
	char id[n][9];
	int morality[n], talent[n], sum[n];
	int flag[n] = {0};

	for (int i=0; i<n; i++) {
		scanf("%s %d %d", id[i], &morality[i], &talent[i]);
		sum[i] = morality[i] + talent[i];
		if (morality[i]>=h && talent[i]>=h)
			flag[i] = 1;
		else if (morality[i]<l || talent[i]<l)
			flag[i] = 0;
		else if (morality[i]>=h)
			flag[i] = 2;
		else if (morality[i]>=talent[i])
			flag[i] = 3;
		else
			flag[i] = 4;
	}

	

	return 0;
}
