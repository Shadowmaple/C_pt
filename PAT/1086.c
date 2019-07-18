# include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int multipy = a * b;
    while (multipy) {
        int x = multipy % 10;
        if (x)
            printf("%d", x);
        multipy /= 10;
    }
    putchar('\n');
    return 0;
}