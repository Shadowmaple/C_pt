#include <stdio.h>

int race(char a, char b)
{
	if (a == b)
		return 0;
	else if (a == 'C') {
		if (b == 'J') return 1; //1代表甲赢，-1为乙赢
		else return -1;
	}
	else if (a == 'J') {
		if (b == 'C') return -1;
		else return 1;
	}
	else if (a == 'B') {
		if (b == 'C') return 1;
		else return -1;
	}
}

int main ()
{
	int N;
	scanf("%d", &N);
	char a[N], b[N];
	int win_a =0, draw_a =0, lose_a =0;
	int win_b =0, draw_b =0, lose_b =0;
	int count_a[3] ={0}, count_b[3] ={0};
	char x[3] = {'C','J','B'};
	for(int i=0; i < N; i++) {
		scanf(" %c %c", &a[i], &b[i]);
		int result = race(a[i], b[i]);
		if (!result) {
			draw_a++;
			draw_b++;
		}
		else if (result == 1) {
			win_a++;
			if (a[i] == 'C') count_a[0]++;
			else if (a[i] == 'J') count_a[1]++;
			else count_a[2]++;
			lose_b++;
		}
		else {
			lose_a++;
			win_b++;
			if (b[i] == 'C') count_b[0]++;
			else if (b[i] == 'J') count_b[1]++;
			else count_b[2]++;
		}
	}
	printf("%d %d %d\n", win_a, draw_a, lose_a);
	printf("%d %d %d\n", win_b, draw_b, lose_b);

	int max =0;
	max = (count_a[max] > count_a[2])? max:2;
	max = (count_a[max] >= count_a[1])? max:1;
	printf("%c ", x[max]);

	max =0;
	max = (count_b[max] > count_b[2])? max:2;
	max = (count_b[max] >= count_b[1])? max:1;
	printf("%c\n", x[max]);

	return 0;
}
