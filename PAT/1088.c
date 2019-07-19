# include <stdio.h>
# include <stdlib.h>

int M, X, Y;

void power(float t)
{
    if (M > t)      printf(" Gai");
    else if (M < t) printf(" Cong");
    else            printf(" Ping");
}

int main()
{
    scanf("%d%d%d", &M, &X, &Y);
    for (int jia = 99; jia >= 10; jia--) {
        int yi = (jia % 10) * 10 + jia / 10;
        float bing = (float) yi / Y;
        if (abs(jia - yi) == bing * X) {
            printf("%d", jia);
            power(jia);
            power(yi);
            power(bing);
            putchar('\n');
            return 0;
        }
    }
    puts("No Solution");
    
    return 0;
}