# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a - *(int *) b;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int obj[n][2];
    for (int i = 0; i < n; i++)
        scanf("%d %d", &obj[i][0], &obj[i][1]);

    for (int i = 0; i < m; i++) {
        int num, flag = 1;
        scanf("%d", &num);
        int item[num];
        for (int j = 0; j < num; j++)
            scanf("%d", item + j);
        
        qsort(item, num, sizeof(int), compar);

        for (int j = 0; j < n; j++) {
            if (bsearch(&obj[j][0], item, num, sizeof(int), compar)
                && bsearch(&obj[j][1], item, num, sizeof(int), compar))
                {
                    puts("No");
                    flag = 0;
                    break;
                }
        }
        if (flag)   puts("Yes");
    }

    return 0;
}