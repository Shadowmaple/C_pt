# include <stdio.h>

int main()
{
    int ascii[127] = {0};
    char x;
    for (int i = 0; i < 2; i++) {
        while ((x = getchar()) != '\n') {
            if (!ascii[(int)x]) {
                ascii[(int)x] = 1;
                putchar(x);
            }
        }
    }
    putchar('\n');
    return 0;
}