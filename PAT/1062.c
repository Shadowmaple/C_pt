# include <stdio.h>

int main()
{
    int a1, b1, a2, b2, K;
    scanf("%d/%d %d/%d %d", &a1, &b1, &a2, &b2, &K);
    double a = (double) a1 / b1;
    double b = (double) a2 / b2;

    // 一个测试点，并没有指定谁大谁小
    if (a > b) {double c = a; a = b; b = c;};
    
    int i = 1, flag = 0;;
    while ((double) i / K <= a) i++;

    for (; (double) i / K < b; i++) {
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
