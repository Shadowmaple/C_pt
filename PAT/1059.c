# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct
{
    int num;    // 排名，0开始
    int flag;   // 奖品是否已取
    char id[5];
} stu;

int isPrime(int num)
{
    int flag = 1;
    // 用 i < sqrt(num) 会有一个测试点通不过
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) {
            flag = 0;
            break;
        }
    // 是素数
    if (flag) return 1;
    else return 0;
}

int compar(const void *a, const void *b)
{
    stu x = *(stu *) a, y = *(stu *) b;
    return strcmp(x.id, y.id);
}

// 对分查找，有序是前提
int search(char *target, stu *competitor, int left, int right, int *no)
{
    int cen = (right + left) / 2;
    if (!strcmp(target, competitor[cen].id)) {
        *no = cen;
        return competitor[cen].num;
    } else if (left > right) return -1;
    else if (strcmp(target, competitor[cen].id) > 0) {
        return search(target, competitor, cen + 1, right, no);
    } else {
        return search(target, competitor, left, cen - 1, no);
    }
}

int main()
{
    int N, K;
    scanf("%d", &N);
    stu competitor[N];
    for (int i=0; i < N; i++) {
        competitor[i].flag = 0;
        competitor[i].num = i;
        scanf("%s", competitor[i].id);
    }
    qsort(competitor, N, sizeof(stu), compar);

    scanf("%d", &K);

    char check[5];
    for (int i=0; i < K; i++) {
        scanf("%s", check);
        int rank, no;
        rank = search(check, competitor, 0, N, &no);

        if (rank == -1) printf("%s: Are you kidding?\n", check);
        else if (competitor[no].flag) {
            printf("%s: Checked\n", check);
            competitor[no].flag = 1;
        } else if (!rank) {
            printf("%s: Mystery Award\n", check); 
            competitor[no].flag = 1;
        } else if (isPrime(rank + 1)) {
            printf("%s: Minion\n", check);
            competitor[no].flag = 1;
        } else {
            printf("%s: Chocolate\n", check);
            competitor[no].flag = 1;
        }
    }

    return 0;
}
