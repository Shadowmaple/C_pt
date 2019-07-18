# include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count = 1, num = 0;

    for (int i = 1; i <= n; i++) {
        int x = i / 2 + i / 3 + i / 5;
        if (x != num) {
            count++;
            num = x;
        }
    }
    printf("%d\n", count);

    return 0;
}