# include <stdio.h>
# include <ctype.h>

int main()
{
    int bad_key[128] = {0};
    char c;

    while (1) {
        scanf("%c", &c);
        if (c == '\n') break;
        bad_key[toupper(c)] = 1;
    }
    while (1) {
        scanf("%c", &c);
        if (c == '\n') break;
        if (!bad_key[toupper(c)] && !(isupper(c) && bad_key['+']))
            printf("%c", c);
    }
    putchar('\n');

    return 0;
}