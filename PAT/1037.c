# include <stdio.h>

int main()
{
    int galleon_p, sickle_p, knut_p;
    int galleon_a, sickle_a, knut_a;
    scanf("%d.%d.%d", &galleon_p, &sickle_p, &knut_p);
    scanf("%d.%d.%d", &galleon_a, &sickle_a, &knut_a);

    long sum_p = galleon_p * 17 * 29 + sickle_p * 29 + knut_p;
    long sum_a = galleon_a * 17 * 29 + sickle_a * 29 + knut_a;
    long minus = sum_a - sum_p;

    int gallen_result, sickle_result, knut_result;
    gallen_result = minus / (17 * 29);
    sickle_result = minus % (17 * 29) / 29;
    knut_result = minus % 29;

    if (sum_a < sum_p)
        printf("%d.%d.%d\n", gallen_result, -sickle_result, -knut_result);
    else
        printf("%d.%d.%d\n", gallen_result, sickle_result, knut_result);

    return 0;
}