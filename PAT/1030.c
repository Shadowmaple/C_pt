# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a < *(int *) b;
}

int main()
{
    int N, p;
    scanf("%d%d", &N, &p);
    int num[N];
    for (int i=0; i < N; i++) {
        scanf("%d", &num[i]);
    }
    qsort(num, N, sizeof(num), compar);

    int length = 0;
    for (int i=0; i + length - 1 < N; i++) {
        for (int j= i + length - 1; j < N; j++) {
            if (num[i] * p < num[j])
                break;
        }
        length = j - i + 1;
    }
    printf("%d\n", length);

    return 0;
}