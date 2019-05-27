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

    int length;
    for (i=0; i < N-1 && half_sort[i] <= half_sort[i+1]; i++) ;
    for (j = i + 1; j < N; j++)
        if (origin[j] != half_sort[j])
            break;
    length = (j == N)? i+2 : 0;

    if (length) {
        puts("Insertion Sort");
        qsort(origin, length, sizeof(int), compar);
    } else {
        puts("Merge Sort");
        for (i=1; i <= N; i *= 2) {
            //如果相等，则再进行一次归并再结束归并的循环
            int flag = 1;
            for (int j=0; j < N; j++)
                if (origin[j] != half_sort[j]) {flag = 0; break;}

            //归并
            length = i * 2;
            for (j=0; j < N / length; j++)
                qsort(origin + length*j, length, sizeof(int), compar);
            qsort(origin + length*j, N % length, sizeof(int), compar);

            if (flag)   break;
        }
    }

    for (i=0; i < N; i++)
        printf("%d%c", origin[i], (i == N-1)? '\n':' ');

    return 0;
}