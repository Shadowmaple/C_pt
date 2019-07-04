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
        return 1;
    else if (x->height < y->height)
        return -1;
    else if (x->name > y->name)
        return 1;
    else return -1;
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
    char row[K][line_max][9];
    int index = 0;

    for (int i = K - 1; i >= 0; i--) {
        // 该排人数
        int num = !i ? line_max : line ;
        // 中间位置
        int cen = num / 2 + 1;
        // 该排的人
        pep row_man[num];
        for (int j = 0; j < num; j++)
            row_man[j] = man[index++];

        qsort(row_man, num, sizeof(pep), compar);

        int j = num - 1;
        strcpy(row[i][cen - 1], row_man[j--].name);
        
        int left = cen - 2, right = cen;
        while (left >= 0 || right < num) {
            if (left >= 0)
                strcpy(row[i][left--], row_man[j--].name);
            
            if (right < num)
                strcpy(row[i][right++], row_man[j--].name);
        }
    }

    for (int i = 0; i < K; i++) {
        int num = !i ? line_max : line;
        for (int j = 0; j < num; j++)
            printf("%s%c", row[i][j], j == num - 1 ? '\n' : ' ');
    }

    return 0;
}