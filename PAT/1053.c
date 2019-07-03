# include <stdio.h>

int main()
{
    int N, D;
    double e;
    scanf("%d %lf %d", &N, &e, &D);

    int K;
    int vacant = 0, or_vacant = 0;
    for (int i=0; i < N; i++) {
        scanf("%d", &K);    // 记录的用电天数
        int less_e = 0;     // 低于阀值的天数

        for (int j=0; j < K; j++) {
            double electric;
            scanf("%lf", &electric);
            if (electric < e)
                less_e++;
        }
        if (less_e > K / 2 && K > D)
            vacant++;
        else if (less_e > K / 2)
            or_vacant++;
    }

    printf("%.1f%% %.1f%%\n", (double) or_vacant / N * 100, (double) vacant / N * 100);

    return 0;
}