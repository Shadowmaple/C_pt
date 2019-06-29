# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

void copy(int *x, int *num, int i, int j)
{
    for (int k=i, m=0; k <= j; k++)
        x[m++] = num[k];
}

void pr(int *x, int n)
{
    for (int i=0; i <= n; i++)
        printf("%d ", x[i]);
    putchar('\n');
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
        int cmp_l, cmp_r;
        if (!i) {
            cmp_r = element > num[i+1];
            cmp_l = !cmp_r;
        } else {
            cmp_l = (element > num[i-1]);
            cmp_r = !cmp_l;
        }
        int flag = 1;
        if (cmp_l) {
            int x[i+1];
            copy(x, num, 0, i);
            qsort(x, i+1, sizeof(int), compar);
            if (x[i] != element)
                flag = 0;
        } else {
            int x[i+1];
            copy(x, num, 0, i);
            qsort(x, i+1, sizeof(int), compar);
            if (x[0] != element)
                flag = 0;
        }
        if (flag && cmp_r) {
            int x[i+1];
            copy(x, num, i, n-1);
            qsort(x, n-i, sizeof(int), compar);
            if (x[n-i-1] != element)
                flag = 0;
        } else if (flag && !cmp_r) {
            int x[i+1];
            copy(x, num, i, n-1);
            qsort(x, n-i, sizeof(int), compar);
            if (x[0] != element)
                flag = 0;
        }

        if (flag) {
            pivot[sum++] = element;
        }
    }

    qsort(pivot, sum, sizeof(int), compar);

    printf("%d\n", sum);
    for (int i=0; i < sum; i++)
        printf("%d%c", pivot[i], (i == sum-1)? '\n':' ');

    return 0;
}
