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
            if (!n)
                puts("tret");
            else if (n <= 12)
                printf("%s\n", mars[n - 1]);
            else if (n <= 24)
                printf("%s\n", mars_high[n-13]);
            else 
                printf("%s %s\n", mars_high[n / 13 - 1], mars[n % 13 - 1]);

        } else {
            if (num[3] == '\0') {
                if (!strcmp(num, "tret")) {
                    printf("%d\n", 0);
                    continue;
                }
                for (int j=0; j < 12; j++) {
                    if (!strcmp(num, mars[j])) {
                        printf("%d\n", j + 1);
                        break;
                    }
                    if (!strcmp(num, mars_high[j])) {
                        printf("%d\n", j + 13);
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
                printf("%d\n", n);
            }
        }
    }

    return 0;
}