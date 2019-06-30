# include <stdio.h>

int main()
{
    int n;
    float num, sum = 0;
    
    scanf("%d", &n);

    for (int i=1; i <= n; i++) {
        scanf("%f", &num);

        sum += num * i * (n - i + 1);
        
    }
    printf("%.2f\n", sum);
    return 0;
}