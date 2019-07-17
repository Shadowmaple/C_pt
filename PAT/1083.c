# include <stdio.h>
# include <string.h>

int main()
{
    int n;
    scanf("%d", &n);
    int count[n];
    for (int i = 0; i < n; i++)
        count[i] = 0;
    
    int num;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        num = (num > i + 1) ? num - i - 1 : i + 1 - num;
        count[num]++;
    }
    for (int i = n - 1; i >= 0; i--)
        if (count[i] >= 2)
            printf("%d %d\n", i, count[i]);
    
    return 0;
}