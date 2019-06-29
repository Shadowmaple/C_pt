# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a - *(int *) b < 0;
}

int main()
{
	int n;
    scanf("%d", &n);
    int num[n];
    int pivot[n], sum = 0; //主元

    for (int i=0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i=0; i < n; i++) {
        int element = num[i];
        int cmp_l = (element > num[i-1]) ? 1:-1;
        int cmp_r = -cmp_l;
        int flag = 0;
        for (int j=0; j < i; j++) {
            if (element - num[j] >= cmp_l)

        }
    }

    qsort(pivot, sum, sizeof(int), compar);

    printf("%d\n", sum);
    for (int i=0; i < sum; i++)
        printf("%d%c", pivot[i], (i == sum-1)? '\n':' ');

    return 0;
}
