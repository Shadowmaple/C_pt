# include <stdio.h>
# include <string.h>

int main()
{
    int M, N, S;
    scanf("%d%d%d", &M, &N, &S);

    char forward[21], winners[M][21];
    int count = 0;
    for (int i = 0, j = S; i < M; i++) {
        scanf("%s", forward);
        if (i + 1 != j) continue;

        int flag = 1;
        for (int k = 0; k < count; k++) {
            if (!strcmp(forward, winners[k])) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            strcpy(winners[count++], forward);
            j += N;
        } else
            j++;
    }
    if (!count) puts("Keep going...");
    for (int i = 0; i < count; i++)
        printf("%s\n", winners[i]);
    
    return 0;
}