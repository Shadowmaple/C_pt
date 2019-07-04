# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct 
{
    char name[9];
    int height;
} pep;

int compar(const void *a, const void *b)
{
    pep *x = (pep *) a;
    pep *y = (pep *) b;
    if (x->height > y->height)
        return -1;  // 置换
    else if (x->height < y->height)
        return 1;
    else if (strcmp(x->name, y->name) < 0)
        return -1;
    else return 1;
}

int main()
{
    int N, K;
    scanf("%d%d", &N, &K);

    pep man[N];

    for (int i=0; i < N; i++)
        scanf("%s%d", man[i].name, &man[i].height);
    
    qsort(man, N, sizeof(pep), compar);

    int line = N / K;   // 每排人数
    int line_max = N % K + line;    // 一排最多人数
    int index = 0;

    for (int i = 0; i < K; i++) {
        // 该排人数
        int num = !i ? line_max : line;
        char name[num][9];
        // 中间位置
        int cen = num / 2 + 1;
        int left = cen - 2, right = cen;
        
        strcpy(name[cen - 1], man[index++].name);
        while (left >= 0 || right < num) {
            if (left >= 0)
                strcpy(name[left--], man[index++].name);
            if (right < num)
                strcpy(name[right++], man[index++].name);
        }

        for (int j = 0; j < num; j++)
            printf("%s%c", name[j], j == num - 1 ? '\n': ' ');
    }

    return 0;
}