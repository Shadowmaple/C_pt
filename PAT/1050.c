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
    k = a = 0;
    b = -1;
    int x = 1;
    while (1) {
        b++;
        while (b < n - i)
            ret[a][b++] = num[k++];
        if (b == n - i && ret[a+1][b-1])
            break;
        b--;

        a++;
        while (a < m - i)
            ret[a++][b] = num[k++];
        if (a == m - i && ret[a-1][b-1])
            break;
        a--;

        b--;
        while (b >= i)
            ret[a][b--] = num[k++];
        if (b < i && ret[a-1][b+1])
            break;
        b++;

        i++;
        a--;
        while (a >= i)
            ret[a--][b] = num[k++];
        if (a < i  && ret[a+1][b+1])
            break;
        a++;
    }

    for (int i=0; i < m; i++)
        for (int j=0; j < n; j++)
            printf("%d%c", ret[i][j], j == n-1 ? '\n' : ' ');
    
    return 0;
}