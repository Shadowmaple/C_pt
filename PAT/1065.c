# include <stdio.h>
# include <stdlib.h>

int compar(const void *a, const void *b)
{
    return *(int *) a > *(int *) b;
}

int main()
{
    int N, M;
    scanf("%d", &N);
    int pep[100000] = {0};

    struct
    { 
        int num;
        int flag;
    } man[N * 2];

    for (int i = 0, index = 0; i < N; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        pep[a] = index + 1;
        man[index].flag = 0;
        man[index++].num = a;

        pep[b] = index + 1;
        man[index].flag = 0;
        man[index++].num = b;
    }

    scanf("%d", &M);
    int single[M], count = 0;
    for (int i = 0; i < M; i++) {
        int guest;
        scanf("%d", &guest);

        if (!pep[guest])
            single[count++] = guest;
        else
            man[pep[guest] - 1].flag = 1;
    }

    for (int i = 0; i < N * 2; i += 2)
        if (!man[i].flag && man[i + 1].flag)
            single[count++] = man[i + 1].num;
        else if (man[i].flag && !man[i + 1].flag)
            single[count++] = man[i].num;

    qsort(single, count, sizeof(int), compar);

    printf("%d\n", count);
    for (int i = 0; i < count; i++)
        // 注意是ID，所以输出为%05d 
        printf("%05d%c", single[i], i == count-1 ? '\n': ' ');

    return 0;
}