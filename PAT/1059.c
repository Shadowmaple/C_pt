# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

typedef struct
{
    int num;
    int flag;
    char id[5];
} stu;

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

int compar(const void *a, const void *b)
{
    stu x = *(stu *) a, y = *(stu *) b;
    return strcmp(x.id, y.id);
}

// 对分查找，有序是前提
int search(char *target, stu *competitor, int left, int right)
{
    int cen = (right + left) / 2;
    if (!strcmp(target, competitor[cen].id)) return competitor[cen].num;
    else if (left > right) return -1;
    else if (strcmp(target, competitor[cen].id) > 0) {
        return search(target, competitor, cen + 1, right);
    } else {
        return search(target, competitor, left, cen - 1);
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

    char check[K][5];
    for (int i=0; i < K; i++) {
        scanf("%s", check[i]);
        int x = search(check[i], competitor, 0, N);

        if (x == -1) printf("%s: Are you kidding?\n", check[i]);
        else if (competitor[x].flag) {
            printf("%s: Checked\n", check[i]);
            competitor[x].flag = 1;
        } else if (!x) {
            printf("%s: Mystery Award\n", check[i]);
            competitor[x].flag = 1;
        } else if (isPrime(x + 1)) {
            printf("%s: Minion\n", check[i]);
            competitor[x].flag = 1;
        } else {
            printf("%s: Chocolate\n", check[i]);
            competitor[x].flag = 1;
        }
    }

    return 0;
}
