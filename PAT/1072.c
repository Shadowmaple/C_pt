# include <stdio.h>
# include <string.h>

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    int confiscate[10000] = {0};
    for (int i = 0; i < M; i++) {
        int num;
        scanf("%d", &num);
        confiscate[num] = 1;
    }

    char name[5];
    int obj, objNum;
    int objTotal = 0, stuTotal = 0;
    for (int i = 0; i < N; i++) {
        scanf("%s%d", name, &objNum);
        int num = 0, flag = 0;
        for (int j = 0; j < objNum; j++) {
            scanf("%d", &obj);
            if (confiscate[obj]) {
                if (!num)
                    printf("%s: %d", name, obj);
                else
                    printf(" %d", obj);
                num++;
                flag = 1;
            }
        }
        if (flag) {
            putchar('\n');
            objTotal += num;
            stuTotal++;
        }
    }
    printf("%d %d\n", stuTotal, objTotal);

    return 0;
}