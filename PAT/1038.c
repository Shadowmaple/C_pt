# include <stdio.h>

int main()
{
    int N, K;
    scanf("%d", &N);
    int num[N];
    for (int i=0; i < N; i++)
        scanf("%d", num + i);
    scanf("%d", &K);
    int grade[K], total[K];
    for (int i=0; i < K; i++) {
        scanf("%d", grade + i);
        total[i] = 0;
    }

    for (int i=0; i < N; i++) {
        for (int j=0; j < K; j++) {
            if (num[i] == grade[j]) {
                total[j]++;
                break;
            }
        }
    }
    for (int i=0; i < K; i++)
        printf("%d%c", total[i], (i==K-1)? '\n':' ');
    
    return 0;
}