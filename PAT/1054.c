# include <stdio.h>
# include <string.h>

int main()
{
    int N;
    scanf("%d", &N);

    char input[N][50];
    int flag[N] = {0};      // 初始化，全为合法
    int count = 0;
    double sum = 0;

    for (int i=0; i < N; i++) {
        scanf("%s", input[i]);
        double point = -1, num = 0;
        char point_c[3] = {0};
        for (int j=0; j < strlen(input[i]); j++) {
            char c = input[i][j];
            if (c != '.' && (c > '9' || c < '0')) {
                flag[i] = 1;
                break;
            } else if (c == '.') {
                if (point != -1) {
                    flag[i] = 1;
                    break;
                } else if (j < strlen(input[i]) - 3) {
                    flag[i] = 1;
                    break;
                } else {
                    point = 0;
                }
            } else {
                if (point == -1) {
                    num = num * 10 + (c - '0');
                } else {
                    point_c[point++] = c;
                }
            }
        } 
        if (!flag[i]) {
            count++;

            point_c[point] = '\0';
            point = 0;
            for (int j = strlen(point_c) - 1; j >= 0; j--) {
                point = point * 0.1 + point_c[j] * 0.1;
            }
            sum += num + point;
        }
    }

    for (int i=0; i < N; i++) {
        if (flag[i])
            printf("ERROR: %s is not a legal number\n", input[i]);
    }
    if (!count)
        printf("The average of 0 numbers is Undefined\n");
    else
        printf("The average of %d numbers is %.2f\n", count, sum / count);

    return 0;
}