# include <stdio.h>
# include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char input[N][100];
    int flag[100] = {0};      // 初始化，全为合法
    int count = 0;
    double sum = 0;

    for (int i=0; i < N; i++) {
        scanf("%s", input[i]);
        
        double point = 0, num = 0;
        int isnum = 0, minus = 0;
        int point_digit = -1;
        char point_c[3] = {0};
        int len = strlen(input[i]);

        for (int j=0; j < len; j++) {
            char c = input[i][j];
            
            if (!j && c == '-') {
                // 负号
                minus = 1;
            } else if (c == '.') {
                if (point_digit != -1) {
                    flag[i] = 1;
                    break;
                } else if (j < len - 3) {
                    flag[i] = 1;
                    break;
                } else {
                    point_digit = 0;
                }
            } else if (c > '9' || c < '0') {
                flag[i] = 1;
                break;
            } else {
                if (point_digit == -1) {
                    isnum = 1;
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
            for (int j = strlen(point_c) - 1; j >= 0; j--)
                point = point * 0.1 + (point_c[j] - '0') * 0.1;

            digit = num + point;
            if (digit > 1000) {
                flag[i] = 1;
                continue;
            }            
            if (minus) digit = -digit;
            
            count++;
            sum += digit;
        }
    }

    for (int i=0; i < N; i++)
        if (flag[i]) printf("ERROR: %s is not a legal number\n", input[i]);
    
    if (!count)
        printf("The average of 0 numbers is Undefined\n");
    else if (count == 1)
        printf("The average of 1 number is %.2f\n", sum);
    else
        printf("The average of %d numbers is %.2f\n", count, sum / count);

    return 0;
}