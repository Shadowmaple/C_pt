# include <stdio.h>
# include <string.h>

int main()
{
    char emoj[3][10][5] = {0};
    int count[3] = {0};

    // 表情符号的输入是关键点
    for (int i=0; i < 3; i++) {
        char c;
        while (1) {
            scanf("%c", &c);
            if (c == '\n') break;
            if (c == '[') {
                scanf("%[^]]", emoj[i][count[i]++]);
                // 格式化字符串"%[^...]"
            }
        }
    }

    int K;
    int choice[5];
    scanf("%d", &K);

    for (int i=0; i < K; i++) {
        for (int j=0; j < 5; j++)
            scanf("%d", &choice[j]);

        if (choice[0] > 0 && choice[0] <= count[0] &&
            choice[1] > 0 && choice[1] <= count[1] &&
            choice[2] > 0 && choice[2] <= count[2] &&
            choice[3] > 0 && choice[3] <= count[1] &&
            choice[4] > 0 && choice[4] <= count[0])
        {
            printf("%s(%s%s%s)%s\n", emoj[0][choice[0]-1], emoj[1][choice[1]-1],
                emoj[2][choice[2]-1], emoj[1][choice[3]-1], emoj[0][choice[4]-1]);
        } else
            puts("Are you kidding me? @\\/@");
    }

    return 0;
}
