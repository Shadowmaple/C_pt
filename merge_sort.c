//归并排序，非递归法

# include <stdio.h>
# include <stdlib.h>

# define N 10

int compar(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

void display(int *num)
{
    for (int i=0; i < N; i++) {
        printf("%d%c", num[i], (i == N-1)? '\n':' ');
    }
}

int main()
{
    int num[N] = {3, 1, 2, 8, 7, 5, 9, 4, 6, 0};
    int i, j, k, length;
    for (i=1; i <= N; i *= 2) {
        length = i * 2;
        for (j=0; j < N / length; j++) {
            qsort(num + j*length, length, sizeof(int), compar);
        }
        qsort(num + j*length, N % length, sizeof(int), compar);
    }
    display(num);
    return 0;
}