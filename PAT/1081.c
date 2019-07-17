// 这题好坑，题目都说了为非空字符串，结果测试点２的输入还是有空格的
// 还有一个坑，全为小数点怎么办？这题没考虑进去

# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char psw[81];
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%[^\n]", psw);
        int len = strlen(psw);
        if (len < 6) {
            puts("Your password is tai duan le.");
            continue;
        }
        int haveDigit = 0, haveAlpha = 0, flag = 0;
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
        
        if (haveAlpha && haveDigit)
            puts("Your password is wan mei.");
        else if (haveAlpha)
            puts("Your password needs shu zi.");
        else
            puts("Your password needs zi mu.");
    }
    return 0;
}