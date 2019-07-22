# include <stdio.h>
# include <math.h>

int main()
{
    int m;
    scanf("%d", &m);
    int num;
    for (int i = 0; i < m; i++) {
        scanf("%d", &num);
        int len = 0, a = num;
        while (a) {
            a /= 10;
            len++;
        }
        
        int flag = 0;
        for (int n = 1; n < 10; n++) {
            int x = num * num * n;
            int y = x % (int)pow(10, len);
            if (y == num) {
                printf("%d %d\n", n, x);
                flag = 1;
                break;
            }
        }
        if (!flag) puts("No");
    }

    return 0;
}