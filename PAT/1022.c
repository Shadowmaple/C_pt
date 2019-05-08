# include <stdio.h>
# include <string.h>
# include <stdlib.h>

void clear_blank(char *num)
{
    int i=0;
    while (num[i] == ' ')
        i++;
    
    strcpy(num, num + i);
}

int main()
{
    int A, B, D;
    scanf("%d%d%d", &A, &B, &D);

    long sum = A + B;
    
    //0为第三个测试点
    if (!sum) {
        puts("0");
        return 0;
    }

    char num[1001];
    memset(num, ' ', 1000);

    int i = 1000;
    while (sum > 0) {
        num[i--] = sum % D + '0';
        sum /= D;
        //printf("_%c\n", num[i+1]);
    }
    num[1001] = '\0';
    clear_blank(num);

    printf("%s\n", num);
    return 0;
}