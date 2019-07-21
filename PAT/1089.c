# include <stdio.h>
# include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    int judge[n], identity[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &judge[i]);
        identity[i] = i + 1;
    }
    for (int i = 0; i < n - 1; i++) {
        // 狼人
        identity[i] = -identity[i];
        for (int j = i + 1; j < n; j++) {
            // 狼人
            if (i == j) continue;
            identity[j] = -identity[j];

            for (int k = 0; k < n; k++) {
                // 撒谎的好人
                if (i == k || j == k) continue;
                // i为撒谎的狼人，或i为诚实的狼人
                if ((identity[abs(judge[i]) - 1] == judge[i]
                    || identity[abs(judge[j]) - 1] != judge[j]
                    || identity[abs(judge[k]) - 1] == judge[k]) && 
                    (identity[abs(judge[i]) - 1] != judge[i]
                    || identity[abs(judge[j]) - 1] == judge[j]
                    || identity[abs(judge[k]) - 1] == judge[k]))
                    continue;

                int flag = 1;
                for (int p = 0; p < n; p++) {
                    // 遍历诚实的好人
                    if (i == p || j == p || k == p) continue;
                    // printf("***%d %d %d %d %d %d\n", i, j, k, p, identity[abs(judge[p]) - 1], judge[p]);
                    if (identity[abs(judge[p]) - 1] != judge[p]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    printf("%d %d\n", i < j? i + 1 : j + 1, i < j? j + 1 : i + 1);
                    return 0;
                }
                
            }
            identity[j] = -identity[j];
        }
        identity[i] = -identity[i];
    }
    puts("No Solution");

    return 0;
}