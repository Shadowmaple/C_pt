# include <stdio.h>

int main()
{
    int ori, N, K;
    scanf("%d%d%d", &ori, &N, &K);
    int data[100000], next[100000];
    int adr;
    for (int i = 0; i < N; i++) {
        scanf("%d", &adr);
        scanf("%d%d", &data[adr], &next[adr]);
    }

    int next_adr = -1;
    for (int i = 0; i < 3; i++) {
        for (adr = ori; adr != -1; adr = next[adr]) {
            if (!i && data[adr] < 0
                || i == 1 && data[adr] <= K && data[adr] >= 0
                || i == 2 && data[adr] > K)
            {   
                if (next_adr != -1) printf("%05d\n", adr);                
                printf("%05d %d ", adr, data[adr]);
                next_adr = adr;
            }
        }
    }
    puts("-1");

    return 0;
}