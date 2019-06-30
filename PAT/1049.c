# include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    float num, sum = 0;

    for (int i=1; i <= n; i++) {
        scanf("%f", &num);

        if (i <= n / 2)
            sum += num * (i * (n - i + 1));
        else {
            int k = n - i + 1;
            sum += num * (k * (n - k + 1));
        }
    }
    printf("%.2f\n", sum);
    return 0;
}