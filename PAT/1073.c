# include <stdio.h>
# include <string.h>
# include <stdlib.h>

typedef struct
{
    int score;
    int aswNum, rightNum;
} question;

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    question qus[M];
    int options[100][5] = {0}, opWroNum[100][5] = {0};
    char x;
    for (int i = 0; i < M; i++) {
        scanf("%d%d%d", &qus[i].score, &qus[i].aswNum, &qus[i].rightNum);
        while (1) {
            scanf("%c", &x);
            if (x == '\n') break;
            if (x != ' ') options[i][x - 97] = 1;
        }
    }

    float grade[N];
    for (int i = 0; i < N; i++) {
        grade[i] = 0;

        for (int j = 0; j < M; j++) {
            do {
                scanf("%c", &x);
            } while (x != '(');

            int isWrong = 0;
            // isWrong : 1为错误，0为正确，-1为半错误
            int num;
            scanf("%d", &num);
            if (num > qus[j].rightNum) isWrong = 1;

            int rightAswNum = 0;
            int op[5] = {0};    // 学生的选项

            while (1) {
                scanf(" %c", &x);
                if (x == ')') break;
                if (x == ' ') continue;
                op[x - 97]++;
            }
            for (int k = 0; k < 5; k++) {
                if (op[k] && options[j][k])
                    rightAswNum++;
                else if (op[k] && !options[j][k]) {
                    // 选到错误选项
                    opWroNum[j][k]++;
                    isWrong = 1;
                } else if (options[j][k])
                    // 没选正确选项
                    opWroNum[j][k]++;
            }

            if (!isWrong && rightAswNum && rightAswNum < qus[j].rightNum)
                isWrong = -1;

            if (isWrong == -1) grade[i] += qus[j].score * 0.5;
            else if (!isWrong) grade[i] += qus[j].score;
        }
        printf("%.1f\n", grade[i]);
    }

    int wrongMax = 0;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < 5; j++)
            if (wrongMax < opWroNum[i][j])
                wrongMax = opWroNum[i][j];

    if (!wrongMax) {
        puts("Too simple");
        return 0;
    }

    for (int i = 0; i < M; i++)
        for (int j = 0; j < 5; j++)
            if (wrongMax == opWroNum[i][j])
                printf("%d %d-%c\n", wrongMax, i + 1, j + 97);
    
    return 0;
}