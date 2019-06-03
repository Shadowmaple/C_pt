# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    int N;
    char mars[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char mars_high[12][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    scanf("%d\n", &N);
    char num[8];
    char num_return[N][8];

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

        //若是数字
        if (isdigit(num[0])) {
            int n = 0;
            for (int j=0; num[j] != '\0'; j++) {
                n = n * 10 + (num[j] - '0');
            }
            //转换为13进制,并输出
            int x = n / 13;
            int y = n % 13;
            if (x) {
                strcpy(num_return[i], mars_high[x-1]);
                num_return[i][3] = ' ';
                num_return[i][4] = '\0';
            } else  {
                num_return[i][0] = '\0';
            }
            strcat(num_return[i], y? mars[y-1] : "tret");
        } else {
            if (num[3] == '\0') {
                if (!strcmp(num_return[i], "tret")) {
                    strcpy(num_return[i], "0");
                    continue;
                }
                for (int j=0; j < 12; j++) {
                    if (!strcmp(num, mars[j])) {
                        char a[][3] = {"1", "2", "3", "4","5","6","7","8","9","10","11","12"};
                        strcpy(num_return[i], a[j]);
                        break;
                    }
                    if (!strcmp(num, mars_high[j])) {
                        char a[][3] = {"13", "14", "15", "16","17","18","19","20","21","22","23","24"};
                        strcpy(num_return[i], a[j]);
                        break;
                    }
                }
            } else {
                int n = 0;
                for (int j=0; j < 12; j++) {
                    if (!strncmp(num, mars_high[j], 3)) {
                        n = j + 1;
                        break;
                    }
                }
                if (!strcmp(num + 4 , "tret")) {
                    n = n * 13;
                } else {
                    for (int j=0; j < 12; j++) {
                        if (!strcmp(num + 4, mars[j])) {
                            n = n * 13 + j + 1;
                        }
                    }
                }
                //十进制数字转换为字符串
                int j=0;
                if (n >= 100) {
                    num_return[i][j++] = n / 100 + '0';
                    n %= 100;
                }
                if (n >= 10) {
                    num_return[i][j++] = n / 10 + '0';
                    n %= 10;
                }
                num_return[i][j++] = n + '0';
                num_return[i][j] = '\0';
            }
        }
    }
    for (int i=0; i < N; i++)
        printf("%s\n", num_return[i]);
    return 0;
}