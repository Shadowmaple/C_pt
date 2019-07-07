# include <stdio.h>
# include <stdlib.h>

int main()
{
    int a1, b1, a2, b2, K;
    scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &K);
    double a = (double) a1 / b1;
    double b = (double) a2 / b2;
    
    int i = 1, flag = 0;;
    while ((double) i / K <= a)
        i++;

    for (; i < K - 2 && (double) i / K < b; i++) {
        int x = i, y = K;
        while (y % x) {
            int c = y % x;
            y = x;
            x = c;
        }
        if (x != 1) continue;

        if (flag) putchar(' ');
        else flag = 1;

        printf("%d/%d", i, K);
    }
    putchar('\n');

    return 0;
}
