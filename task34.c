#include <stdio.h>

int main()
{
	int a, a_, b, b_;
	int n;
	scanf("%d", &n);
	int count_a=0, count_b=0;

	while (n--) {
		scanf("%d%d%d%d", &a, &a_, &b, &b_);
		int sum =a + b;
		int check_a=0, check_b=0;
		if (sum == a_)
			check_a =1;
		if (sum == b_)
			check_b =1;

		if (check_a > check_b)
			count_b++;
		else if (check_a < check_b)
			count_a++;
	}
	printf("%d %d\n", count_a, count_b);
	return 0;
}
