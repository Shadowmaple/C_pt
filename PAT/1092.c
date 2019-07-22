# include <stdio.h>

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int quantity[1000] = {0}, max = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int amount;
            scanf("%d", &amount);
            quantity[j] += amount;
            if (i == m - 1 && max < quantity[j]) max = quantity[j]; 
        }
    }
    printf("%d\n", max);
    
    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (quantity[i] == max) {
            if (!flag) flag = 1;
            else       putchar(' ');
            printf("%d", i + 1);
        }
    }
    putchar('\n');
    return 0;
}