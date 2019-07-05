# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    char c;
    int count = 0, sum = 0;

    while (1) {
        scanf("%c", &c);
        if (c == '\n') break;
        if (isalpha(c)) {
            count++;
            sum += (c >= 97) ? c - 96 : c - 64;
        }
    }

    int zero = 0, one = 0;
    int x;
    while (sum != 0) {
        x = sum % 2;
        if (x) one++;
        else zero++;
        sum /= 2;
    }

    printf("%d %d\n", zero, one);

    return 0;
}