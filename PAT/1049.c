# include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    float num[n], sum = 0;

    for (int i=0; i < n; i++)
        scanf("%f", &num[i]);

    for (int i=1; i <= n; i++) {
        if (i <= n / 2)
            sum += num[i - 1] * (i * (n - i + 1));
        else {
            int k = n - i + 1;
            sum += num[i - 1] * (k * (n - k + 1));
        }
    }
    printf("%.2f\n", sum);
    return 0;
}