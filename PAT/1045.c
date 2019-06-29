// 有点难度，自己的两种做法都超时，PTA上通过率为0.18

# include <stdio.h>

int main()
{
	int n;
    scanf("%d", &n);
    int num[n], lmax[n], rmin[n];
    int pivot[n], sum = 0; //主元

    for (int i=0; i < n; i++)
        scanf("%d", &num[i]);

    for (int i = 0, max = 0; i < n; i++)
        lmax[i] = num[i] > num[max] ? num[max = i] : num[max];

    for (int i = n-1, min = i; i >= 0; i--)
        rmin[i] = num[i] < num[min] ? num[min = i] : num[min];

    for (int i = 0; i < n; i++) {
        if (num[i] == lmax[i] && num[i] == rmin[i])
            pivot[sum++] = num[i];
    }

    printf("%d\n", sum);
    for (int i=0; i < sum; i++)
        printf("%d%c", pivot[i], (i == sum-1)? '\n':' ');
    if (!sum) putchar('\n');

    return 0;
}
