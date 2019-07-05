# include <stdio.h>
# include <string.h>
# include <ctype.h>
# include <stdlib.h>

typedef struct
{
    int id;
    // 满分值，选项个数，正确选项个数
    int score, num, right_num;
    // 选项
    char choice[6];
    // 错误数
    int count;
} qes;

int compar(const void *a, const void *b)
{
    qes x = *(qes *) a, y = *(qes *) b;
    if (x.count > y.count || x.count == y.count && x.id < y.id)
        return -1;
    else
        return 1;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    qes pr[M];
    for (int i=0; i < M; i++) {
        pr[i].id = i + 1;
        pr[i].count = 0;
        scanf("%d%d%d", &pr[i].score, &pr[i].num, &pr[i].right_num);
        char c;
        int index = 0;
        while (1) {
            scanf("%c", &c);
            if (c == '\n') break;
            if (islower(c))
                pr[i].choice[index++] = c;
        }
        pr[i].choice[index] = '\0';
    }

    int grade[N];
    for (int i=0; i < N; i++) {
        grade[i] = 0;
        char c;
        int k = 0;
        while (1) {
            scanf("%c", &c);
            if (c == '\n') break;

			if (isdigit(c)) {
				if (c - '0' != pr[k].right_num) {
					pr[k].count++;
					k++;
				} else {
					int index = 0;
					int flag = 1;
					while (1) {
						scanf("%c", &c);
						if (c == ')')
							break;
						else if (isalpha(c) && c != pr[k].choice[index++]) {
							flag = 0;
							break;
						}
					}
					if (flag)
						grade[i] += pr[k].score;
					else
						pr[k].count++;
					k++;
				}
			}
		}
    }

    for (int i=0; i < N; i++)
        printf("%d\n", grade[i]);

    qsort(pr, M, sizeof(qes), compar);

    int max = pr[0].count;
    if (!max) {
        puts("Too simple");
        return 0;
    }
    int i = 1;
    printf("%d %d", max, pr[0].id);
    while (pr[i].count == max)
        printf(" %d", pr[i++].id);

    putchar('\n');
    return 0;
}
