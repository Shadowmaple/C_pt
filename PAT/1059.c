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

int compar(const void *a, const void *b)
{

}

int search(char *target, char (*id)[5], int left, int right)
{
    int cen = (right + left) / 2;
    if (!strcmp(target, id[cen])) return cen;
    else if (left > right) return -1;
    int x = search(target, id, left, cen - 1);
    int y = search(target, id, cen + 1, right);
    if (x != -1) return x;
    if (y != -1) return y;
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
    qsort()
    for (int i=0; i < K; i++) {
        scanf("%s", check[i]);
        int x = search(check[i], id, 0, N);

        if (x == -1) printf("%s: Are you kidding?\n", check[i]);
        else if (flag[x]) {
            printf("%s: Checked\n", check[i]);
            flag[x] = 1;
        } else if (!x) {
            printf("%s: Mystery Award\n", check[i]);
            flag[x] = 1;
        } else if (isPrime(x + 1)) {
            printf("%s: Minion\n", check[i]);
            flag[x] = 1;
        } else {
            printf("%s: Chocolate\n", check[i]);
            flag[x] = 1;
        }
    }

    return 0;
}
