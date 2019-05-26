# include <stdio.h>

//辗转相除法，求最大公因数
long num(long a, long b)
{
    long x = a % b;
    while (x) {
        a = b;
        b = x;
        x = a % b;
    }
    return b;
}

void display(long a, long b)
{
    if (!b) {
        printf("Inf");
        return ;
    }

    int positive = 1;
    if (a < 0) {
        a = -a;
        positive = -positive;
    }
    if (b < 0) {
        b *= -1;
        positive *= -1;
    }

    long n = num(a, b);
    a /= n;
    b /= n;

    if (positive == -1) printf("(-");
    if (a / b && a % b) printf("%ld %ld/%ld", a / b, a % b, b);
    else if (a % b)     printf("%ld/%ld", a % b, b);
    else                printf("%ld", a / b);
    if (positive == -1) printf(")");
}

int main()
{
    long a1, b1, a2, b2;
    char sign[4] = {'+', '-', '*', '/'};
    scanf("%ld/%ld %ld/%ld", &a1, &b1, &a2, &b2);

    for (int i=0; i < 4; i++) {
        display(a1, b1);
        printf(" %c ", sign[i]);
        display(a2, b2);
        printf(" = ");
        switch (sign[i])
        {
            case '+': display(a1 * b2 + a2 * b1, b1 * b2); break;
            case '-': display(a1 * b2 - a2 * b1, b1 * b2); break;
            case '*': display(a1 * a2,           b1 * b2); break;
            case '/': display(a1 * b2,           a2 * b1); break;
        }
        putchar('\n');
    }
    return 0;
}