# include <stdio.h>

//化简分数
void simplify(int *a, int *b)
{
    int sign = (*a >= 0) ? 1 : 0;
    int x = *a, y = *b;
    //若符号为负号，则取其相反数
    if (!sign)
        x = -x;
    for (int i=2; i <= x && i <= y; i++) {
        if (x % i || y % i)
            continue;
        x /= i;
        y /= i;
        i--;
    }
    *a = (sign) ? x : -x;
    *b = y;
}

//假分数转为真分数
void convert(int *a, int *b, int *c)
{
    *c = *a / *b;
    *a %= *b;
}

int main()
{
    int a1, b1, a2, b2;
    scanf("%d/%d %d/%d", &a1, &b1, &a2, &b2);

    simplify(&a1, &b1);
    simplify(&a2, &b2);
    //符号，正数为1，负数为0;
    int sign_1 = (a1 >= 0) ? 1 : 0;
    int sign_2 = (a2 >= 0) ? 1 : 0;
    //公共的分母数
    int b_both = b1 * b2;


    return 0;
}