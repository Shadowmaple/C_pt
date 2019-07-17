# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char psw[81];
    for (int i = 0; i < n; i++) {
        scanf("%s", psw);
        int len = strlen(psw);
        if (len < 6) {
            puts("Your password is tai duan le.");
            continue;
        }
        int haveDigit = 0, haveAlpha = 0;
        int flag = 0;
        for (int j = 0; j < len; j++) {
            if (psw[j] != '.' && !isalnum(psw[j])) {
                puts("Your password is tai luan le.");
                flag = 1;
                break;
            }
            if (isdigit(psw[j])) haveDigit = 1;
            if (isalpha(psw[j])) haveAlpha = 1;
        }
        if (flag) continue;

        if (haveAlpha && !haveDigit)
            puts("Your password needs shu zi.");
        else if (!haveAlpha && haveDigit)
            puts("Your password needs zi mu.");
        else
            puts("Your password is wan mei.");
            
    }
    return 0;
}