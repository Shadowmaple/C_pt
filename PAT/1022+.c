//看大神的方法

#include <stdio.h>

int main()
{
    int A, B, D, sum;
    scanf("%d %d %d", &A, &B, &D);
    sum = A + B;

    /* calculate the bits of sum */
    int power = 1;
    /* use sum / D >= power to avoid using long int */
    while(sum / D >= power) power *= D;

    /* calculate D-base number. print them on-the-fly */
    for(; power > 0; sum %= power, power /= D)
        printf("%d", sum / power);

    return 0;
}