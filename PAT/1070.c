# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int compar(const void *a, const void *b)
{
    return *(int *) a < *(int *) b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", num + i);

    qsort(num, n, sizeof(int), compar);

    int max = num[0] / 2 + num[1] / 2;
    for (int i = 2; i < n; i++) {
        int len = max / 2 + num[i] / 2;
        if (max > len) break;
        max = len;
    }

    printf("%d\n", max);

    return 0;
}