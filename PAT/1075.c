# include <stdio.h>

int main()
{
    int ori, N, K;
    scanf("%d%d%d", &ori, &N, &K);
    int data[100000], next[100000];
    int adr;
    int count_minus = 0, count_in_K = 0, count_by_K = 0;
    int pre[100000], cet[100000], aft[100000];
    int ele[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &data[adr], &next[adr]);
        ele[i] = adr;
    }
    // puts("---");

    for (int i = 0; i < N - 1; i++) {
        int target = !i ? ori : next[ele[i - 1]];
        int k = i;
        if (target == -1) break;
        for (int j = i + 1; j < N; j++) {
            if (target == ele[j]) {
                k = j;
                break;
            }
        }
        if (k != i) {
            int x = ele[i];
            ele[i] = ele[k];
            ele[k] = x;
        }
    }

    for (int i = 0; i < N; i++)
        if (data[ele[i]] < 0) {
            pre[count_minus] = ele[i];
            count_minus++;
        } else if (data[ele[i]] <= K) {
            cet[count_in_K] = ele[i];
            count_in_K++;
        } else {
            aft[count_by_K] = ele[i];
            count_by_K++;
        }
    
    int i;
    for (i = 0; i < count_minus - 1; i++)
        printf("%05d %d %05d\n", pre[i], data[pre[i]], pre[i + 1]);
    printf("%05d %d %05d\n", pre[i], data[pre[i]], cet[0]);
    
    for (i = 0; i < count_in_K - 1; i++)
        printf("%05d %d %05d\n", cet[i], data[cet[i]], cet[i + 1]);
    printf("%05d %d %05d\n", cet[i], data[cet[i]], aft[0]);

    for (i = 0; i < count_by_K - 1; i++)
        printf("%05d %d %05d\n", aft[i], data[aft[i]], aft[i + 1]);
    printf("%05d %d %d\n", aft[i], data[aft[i]], -1);

    return 0;
}