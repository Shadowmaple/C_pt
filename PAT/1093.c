# include <stdio.h>

int main()
{
    int ascii[126] = {0}, blank = 0;
    for (int i = 0; i < 2; i++) {
        int x;
        while ((x = getchar()) != '\n') {
            if (x == ' ' && !blank) {
                blank = 1;
                putchar(x);
            } else if(!ascii[x - '0']) {
                ascii[x - '0'] = 1;
                putchar(x);
            }
        }
    }
    putchar('\n');

    return 0;
}