# include <stdio.h>
# include <string.h>

int main()
{
    int n;
    char pw[21];
    scanf("%s%d", pw, &n);

    char try[21];
    while (n--) {
        scanf("%s", try);

        if (!strcmp(try, "#")) break;
        else if (!strcmp(try, pw)) {
            puts("Welcome in");
            break;
        } else {
            printf("Wrong password: %s\n", try);
            if (!n)     puts("Account locked");
        }
    }
    return 0;
}