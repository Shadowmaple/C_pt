# include <stdio.h>
# include <string.h>

int main()
{
    int n;
    char pw[21];
    scanf("%s%d", pw, &n);
    getchar();

    char try[21];
    while (n--) {
        // 重点
        scanf("%20[^\n]", try);
        char c = getchar();

        if (!strcmp(try, "#")) break;
        else if (!strcmp(try, pw) && c == '\n') {
            puts("Welcome in");
            break;
        } else {
            printf("Wrong password: %s", try);
            if (c != '\n') {
                printf("%c", c);
                while (1) {
                    scanf("%c", &c);
                    if (c == '\n') break;
                    printf("%c", c);
                }
            }
            putchar('\n');
            if (!n)     puts("Account locked");
        }
    }
    return 0;
}