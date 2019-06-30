# include <stdio.h>

int main()
{
    int n;
    double num, sum = 0;
    // 用float有两个测试点会通不过
    
    scanf("%d", &n);

    for (int i=1; i <= n; i++) {
        scanf("%lf", &num);

        sum += num * i * (n - i + 1);
    }
    printf("%.2f\n", sum);
    return 0;
}