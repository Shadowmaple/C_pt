# include <stdio.h>
# include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char input[N][50];
    int flag[100] = {0};      // 初始化，全为合法
    int count = 0;
    double sum = 0;

    for (int i=0; i < N; i++) {
        scanf("%s", input[i]);
        double point = 0, num = 0;
        int point_digit = -1;
        int minus = 0;
        char point_c[3] = {0};
        for (int j=0; j < strlen(input[i]); j++) {
            char c = input[i][j];
            if (!j && c == '-') {
                // 负号
                minus = 1;
            } else if (c == '.') {
                if (point_digit != -1) {
                    flag[i] = 1;
                    // putchar('1');
                    break;                    
                } else if (j < strlen(input[i]) - 3) {
                    flag[i] = 1;
                    // putchar('2');
                    break;
                } else {
                    point_digit = 0;
                }
            } else if (c > '9' || c < '0') {
                flag[i] = 1;
                // putchar('3');
                break;
            } else {
                if (point_digit == -1) {
                    num = num * 10 + (c - '0');
                } else {
                    point_c[point_digit++] = c;
                }
            }
        }
        
        double digit = 0;
        if (!flag[i]) {
            point_c[point_digit] = '\0';
            // 计算小数位
            for (int j = strlen(point_c) - 1; j >= 0; j--) {
                point = point * 0.1 + (point_c[j] - '0') * 0.1;
            }

            digit = num + point;
            if (digit > 1000) {
                flag[i] = 1;
                // putchar('4');
                continue;
            }
            if (minus) digit = -digit;
            
            count++;
            sum += digit;
        }
        // puts(" //");
    }

    for (int i=0; i < N; i++)
        if (flag[i])
            printf("ERROR: %s is not a legal number\n", input[i]);
    
    if (!count)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d numbers is %.2f\n", count, sum / count);

    return 0;
}