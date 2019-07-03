# include <stdio.h>
# include <string.h>

int main()
{
    char emoj[3][10][5] = {0};
    int count[3] = {0};
    int K;

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

    for (int i=0; i < 3; i++) {
        for (int j=0; j < count[i]; j++)
            printf("%s ", emoj[i][j]);
        putchar('\n');
    }


    return 0;
}
