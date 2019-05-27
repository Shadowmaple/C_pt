# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N;
    scanf("%d", &N);
    int origin[N], half_sort[N];
    int i, j;
    for (i=0; i < N; i++)
        scanf("%d", origin + i);
    for (i=0; i < N; i++)
        scanf("%d", half_sort + i);

    int length = 0;
    for (i=0; i < N-1 && half_sort[i] <= half_sort[i+1]; i++) ;
    for (j = i + 1; j < N; j++)
        if (origin[j] != half_sort[j])
            break;
    length = (j == N)? i+1 : 0;

    if (length) {
        puts("Insertion Sort");
        qsort(half_sort, length, sizeof(int), compar);
    } else {

    }

    for (i=0; i < N; i++)
        printf("%d%c", half_sort[i], (i == N-1)? '\n':' ');

    return 0;
}