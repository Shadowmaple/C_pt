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
            }
        }
    }

/*  
    // 不知道为什么这样只读到乱码
    for (int i=0; i < 3; i++) {
        int flag = 0;
        int k = 0;
        while (1) {
            char c;
            scanf("%c", &c);
            if (c == '\n') break;
            if (c == '[') {
                flag = 1;
            } else if (c == ']') {
                flag = 0;
                emoj[i][count[i]][k] = '\0';
                count[i]++;
            } else if (flag) {
                emoj[i][count[i]][k++] = c;
            }
        }
        count[i]--;
    }
    */

    int K;
    int choice;
    scanf("%d", &K);

    for (int i=0; i < K; i++) {
        char expe[50];
        expe[0] = '\0';
        int j;
        for (j=0; j < 5; j++) {
            scanf("%d", &choice);

            if (!j || j == 4) {
                if (choice > count[0]) {
                    puts("Are you kidding me? @\\/@");
                }
                strcat(expe, emoj[0][choice - 1]);
                if (!j) strcat(expe, "(");
            } else if (j == 2) {
                if (choice > count[2]) {
                    puts("Are you kidding me? @\\/@");
                    break;
                }
                strcat(expe, emoj[2][choice - 1]);
            } else {
                if (choice > count[1]) {
                    puts("Are you kidding me? @\\/@");
                    break;
                }
                strcat(expe, emoj[1][choice - 1]);
                if (j == 3) strcat(expe, ")");
            }
        }
        if (j == 5)
            printf("%s\n", expe);
    }

    return 0;
}
