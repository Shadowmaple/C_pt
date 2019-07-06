# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdlib.h>

int isPrime(int num)
{
    for (int i = 2; i < sqrt(num); i++)
        if (num % i == 0)
            return 0;
    return 1;
}

int main()
{
    int N, K, id;
    int award[10000] = {0};

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &id);
        if (!i) award[id] = 1;
        else if (isPrime(i + 1)) award[id] = 2;
        else award[id] = 3;
    }

    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &id);
        switch (award[id]) {
            case 0: printf("%04d: Are you kidding?\n", id); break;
            case 1: printf("%04d: Mystery Award\n", id); award[id] = 4; break;
            case 2: printf("%04d: Minion\n", id); award[id] = 4; break;
            case 3: printf("%04d: Chocolate\n", id); award[id] = 4; break;
            case 4: printf("%04d: Checked\n", id); break;
        }
    }
    
    return 0;
}
