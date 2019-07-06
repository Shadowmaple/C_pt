# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a < *(int *) b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int s[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &s[i]);
    
    qsort(s, n, sizeof(int), compar);

    int e = 0;
    for (int i = 0; i < n && s[i] > e + 1; i++)
        if (s[i] > e) e++;

    printf("%d\n", e);
    
    return 0;
}