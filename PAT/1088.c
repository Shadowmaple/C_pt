# include <stdio.h>
# include <stdlib.h>

void power(int m, int t, float w)
{
    if (w) t = w;
    if (m > t)      printf("Gai");
    else if (m < t) printf("Cong");
    else            printf("Ping");
}

int main()
{
    int M, X, Y;
    scanf("%d%d%d", &M, &X, &Y);
    int jia, yi;
    float bing;
    int flag = 0;
    for (jia = 99; jia >= 10; jia--) {
        yi = (jia % 10) * 10 + jia / 10;
        bing = (float) yi / Y;
        if (abs(jia - yi) == bing * X) {
            flag = 1;
            break;
        }
    }
    if (!flag) {
        puts("No Solution");
        return 0;
    }

    // printf("%d %d %f\n", jia, yi, bing);
    printf("%d ", jia);
    power(M, jia, 0);      putchar(' ');
    power(M, yi, 0);       putchar(' ');
    power(M, 0, bing);     putchar('\n');
    
    return 0;
}