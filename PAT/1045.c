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
        int cmp_l = (element > num[i-1]);
        int cmp_r = !cmp_l;
        int flag = 1;
        if (cmp_l) {
            for (int j=0; j < i; j++) {
                if (element > num[j])
                    continue;
                flag = 0;
                break;
            }
        } else {
            for (int j=0; j < i; j++) {
                if (element < num[j])
                    continue;
                flag = 0;
                break;
            }
        }
        if (flag && cmp_r) {
            for (int j=i; j < n; j++) {
                if (element > num[j])
                    continue;
                flag = 0;
                break;
            }
        } else if (flag && !cmp_r) {
            for (int j=i; j < n; j++) {
                if (element < num[j])
                    continue;
                flag = 0;
                break;
            }
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
