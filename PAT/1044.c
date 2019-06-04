# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    int N;
    char mars[13][5] = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char mars_high[12][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    char num[8];
    scanf("%d\n", &N);

    for (int i=0; i < N; i++) {
        // scanf("%[^\n]", num);
        int j=0;
        while (1) {
            scanf("%c", &num[j]);
            if (num[j] == '\n' || j == 7)
                break;
            j++;
        }
        num[j] = '\0';

        //若是地球数字
        if (isdigit(num[0])) {
            int n = 0;
            for (int j=0; num[j] != '\0'; j++) {
                n = n * 10 + (num[j] - '0');
            }
            if (n <= 12)
                printf("%s\n", mars[n]);
            else if (n % 13)
                printf("%s %s\n", mars_high[n / 13 - 1], mars[n % 13]);
            else
                // 末尾的零不能保留，像英文里的一样，如20--twenty
                printf("%s\n", mars_high[n / 13 - 1]);
        
        } else {
            //若是火星文
            //一个火星文的情况
            if (num[3] == '\0' || num[3] == 't') {
                for (int j=0; j < 13; j++) {
                    if (!strcmp(num, mars[j])) {
                        printf("%d\n", j);
                        break;
                    }
                    // 单个进位火星文
                    if (!strcmp(num, mars_high[j])) {
                        printf("%d\n", (j + 1) * 13);
                        break;
                    }
                }
            } else {
                // 两个火星文的情况
                int n = 0;
                // 计算第一个火星文
                for (int j=0; j < 12; j++) {
                    if (!strncmp(num, mars_high[j], 3)) {
                        n = j + 1;
                        break;
                    }
                }
                // 第二个火星文
                for (int j=0; j < 13; j++) {
                    if (!strcmp(num + 4, mars[j])) {
                        n = n * 13 + j;
                    }
                }
                printf("%d\n", n);
            }
        }
    }

    return 0;
}