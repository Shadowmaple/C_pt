# include <stdio.h>
# include <string.h>
# include <stdlib.h>

int check(long num)
{
    for (int i = 2; i * i < num; i++) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int L, K;
    scanf("%d %d", &L, &K);
    char N[L + 1], num[10] = {0};
    scanf("%s", N);

    for (int i = 0; i <= L - K; i++) {
        strncpy(num, N + i, K);
        if (check(atoi(num))) {
            printf("%s\n", num);
            return 0;
        }
    }
    puts("404");
    return 0;
}