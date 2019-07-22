# include <stdio.h>
# include <string.h>

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
    char N[L + 1];
    scanf("%s", N);

    for (int i = 0; i <= L - K; i++) {
        long num = 0, len = 0;
        for (int j = i; j < i + K; j++) {
            num = num * 10 + (N[j] - '0');
            if (N[j] != '0') len++;
        }
        
        if (check(num)) {
            if (len == K) {
                printf("%ld\n", num);
                return 0;    
            }
            char x[K + 1];
            for (int p = K - 1; p >= 0; p--) {
                x[p] = num % 10 + '0';
                num /= 10;
            }
            x[K] = '\0';
            printf("%s\n", x);
            return 0;
        }
    }
    puts("404");

    return 0;
}