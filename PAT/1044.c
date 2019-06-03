# include <stdio.h>
# include <string.h>
# include <ctype.h>

int main()
{
    int N;
    char mars[12][4] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    char mars_high[12][4] = {"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};

    scanf("%d", &N);
    char num[8];
    char num_return[N][8];

    for (int i=0; i < N; i++) {
        scanf("%s", num);
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
            if (strlen(num[i]) == 3) {
                 {
                    strcpy(num_return[i], "0");
                    continue;
                }
                for (int j=0; j < 12; j++) {
                    if (!strcmp(num[i], mars[j])) {
                        strcpy(num_return[i], j + 1 + '0');
                        break;
                    }
                }
            } else {
                int n = 0;
                for (int j=0; j < 12; j++) {
                    if (!strncmp(num[i], mars_high[j], 3)) {
                        n = j + 1;
                        break;
                    }
                }
                if (!strcmp(num[i] + 4 , "tret")) {
                    n = n * 13;
                } else {
                    for (int j=0; j < 12; j++) {
                        if (!strcmp(num[i] + 4, mars[j])) {
                            n = n * 13 + j + 1;
                        }
                    }
                }
                //十进制数字转换为字符串
                
            }
        }
    }
    for (int i=0; i < N; i++)
        printf("%s\n", num_return[i]);
    return 0;
}