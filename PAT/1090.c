# include <stdio.h>

typedef struct
{
    int element[10];
    int count;
} contrary;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    contrary obj[100000] = {0};
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        obj[a].element[obj[a].count++] = b;
        obj[b].element[obj[b].count++] = a;
    }

    for (int i = 0; i < m; i++) {
        int num, flag = 1;
        scanf("%d", &num);
        int g[num];
        for (int j = 0; j < num; j++) {
            scanf("%d", &g[j]);
        }
        for (int j = 0; j < num - 1; j++) {
            for (int k = j + 1; k < num; k++) {
                for (int p = 0; p < obj[g[j]].count; p++) {
                    if (obj[g[j]].element[p] == g[k]) {
                        flag = 0;
                        puts("No");
                        break;
                    }
                }
                if (!flag) break;
            }
            if (!flag) break;
        }
        if (flag) puts("Yes");
    }

    return 0;
}