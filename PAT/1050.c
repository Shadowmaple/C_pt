# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int compar(const void *a, const void *b)
{
    return *(int *) b - *(int *) a;
}

int main()
{
    int N;
    scanf("%d", &N);
    int num[N];
    for (int i=0; i < N; i++)
        scanf("%d", &num[i]);
    
    qsort(num, N, sizeof(int), compar);

    int m, n, min = N;
    for (int b = sqrt(N), a = N / b; a >= b; b++, a--) {
        if (a * b != N) continue;
        if (min > a - b) {
            min = a - b;
            m = a;
            n = b;
        }
    }
    int ret[m][n];

    for (int i = 0; i < m; i++)
        for (int j=0; j < n; j++)
            ret[i][j] = 0;

    int k , a, b;
    int i = 0;
    k = a = b = 0;
    while (1) {
        while (b < n - i && !ret[a][b])
            ret[a][b++] = num[k++];
        if (b <= n - i && ret[a][b])
            break;
        b--;

        while (a < m - i && !ret[a][b])
            ret[a++][b] = num[k++];
        if (a <= m - i && ret[a][b])
            break;
        a--;

        while (b >= i && !ret[a][b])
            ret[a][b--] = num[k++];
        if (b >= i - 1 && ret[a][b])
            break;
        b++;

        i++;
        while (a >= i && !ret[a][b])
            ret[a--][b] = num[k++];
        if (a >= i - 1 && ret[a][b])
            break;
        a++;
    }
    for (int i=0; i < m; i++)
        for (int j=0; j < n; j++)
            printf("%d%c", ret[i][j], j == n-1 ? '\n' : ' ');
    
    return 0;
}