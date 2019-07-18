# include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int multipy = a * b;
    
    while (!(multipy % 10))
        multipy /= 10;

    while (multipy) {
        printf("%d", multipy % 10);
        multipy /= 10;
    }
    putchar('\n');
    return 0;
}