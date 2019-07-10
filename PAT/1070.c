# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a > *(int *) b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int num[n];
    for (int i = 0; i < n; i++)
        scanf("%d", num + i);

    qsort(num, n, sizeof(int), compar);

    int len = num[0] / 2 + num[1] / 2;
    for (int i = 2; i < n; i++)
        len = (len + num[i]) / 2;

    printf("%d\n", len);

    return 0;
}